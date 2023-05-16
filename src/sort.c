/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:00:22 by araymond          #+#    #+#             */
/*   Updated: 2023/05/09 12:17:49 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "utils.h"

static void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	while ((*stack_b)->size > 0)
	{
		temp = get_highest(stack_b);
		if (is_faster(stack_b, temp) == 1)
		{
			while ((*stack_b)->index != temp->index)
				rotate_b(stack_b, 0);
			push_a(stack_a, stack_b);
		}
		else
		{
			while ((*stack_b)->index != temp->index)
				reverse_rotate_b(stack_b, 0);
			push_a(stack_a, stack_b);
		}
	}
}

void	large_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		low;
	int		chunk;

	low = 1;
	chunk = 20;
	while ((*stack_a)->size != 0)
	{
		if ((*stack_a)->index >= low && (*stack_a)->index <= chunk + low)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a, 0);
		low = get_lowest(stack_a);
	}
	push_back(stack_a, stack_b);
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		index;

	index = (*stack_a)->size;
	while ((*stack_a)->size > 3)
	{
		temp = (*stack_a);
		if (temp->index == 1 || temp->index == 2)
			push_b(stack_a, stack_b);
		if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
			continue ;
		rotate_a(stack_a, 0);
	}
	small_sort(stack_a, stack_b);
	if ((*stack_b)->index > (*stack_b)->next->index)
	{
		while ((*stack_b)->size > 0)
			push_a(stack_a, stack_b);
	}
	else
	{
		swap_b(stack_b, 0);
		while ((*stack_b)->size > 0)
			push_a(stack_a, stack_b);
	}
}

void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	if ((*stack_a)->size == 2)
	{
		swap_a(stack_a, 0);
		return ;
	}
	if ((*stack_a)->size == 3)
	{
		while (is_sorted(stack_a) != SUCCESS)
		{
			reverse_rotate_a(stack_a, 0);
			if ((*stack_a)->value > (*stack_a)->next->value)
				swap_a(stack_a, 0);
		}
	}
}

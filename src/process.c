/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:46:49 by araymond          #+#    #+#             */
/*   Updated: 2023/05/11 14:49:06 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ops.h"

static void	medium_sort_exception(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		index;

	index = (*stack_a)->size;
	while ((*stack_a)->size > 3)
	{
		temp = (*stack_a);
		if (temp->index == 1)
			push_b(stack_a, stack_b);
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

void	start_process(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = initiate_stack();
	if (!stack_b)
		error_message(stack_a, NULL, NULL);
	if (is_sorted(stack_a) == SUCCESS)
	{
		clear_stack(stack_a);
		clear_stack(&stack_b);
		return ;
	}
	if ((*stack_a)->size <= 3)
		small_sort(stack_a, &stack_b);
	else if ((*stack_a)->size == 4)
		medium_sort_exception(stack_a, &stack_b);
	else if ((*stack_a)->size == 5)
		medium_sort(stack_a, &stack_b);
	else if ((*stack_a)->size >= 6)
		large_sort(stack_a, &stack_b);
	clear_stack(stack_a);
	clear_stack(&stack_b);
}

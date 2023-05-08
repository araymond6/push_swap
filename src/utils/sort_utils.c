/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:47:47 by araymond          #+#    #+#             */
/*   Updated: 2023/05/04 11:35:16 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"
#include "../ops.h"

// If reverse if faster, returns 0, otherwise returns 1.
int	is_faster(t_stack **stack, t_stack *temp)
{
	int		i;
	int		j;
	t_stack	*temp2;

	temp2 = *stack;
	i = 0;
	j = 0;
	while (temp2->index != temp->index)
	{
		temp2 = temp2->next;
		i++;
	}
	temp2 = *stack;
	while (temp2->index != temp->index)
	{
		temp2 = temp2->prev;
		j++;
	}
	if (i >= j)
		return (0);
	return (1);
}

// Checks if the stack is sorted; 0 if not sorted, 1 if sorted.
int	is_sorted(t_stack **stack)
{
	t_stack	*temp;
	int		low;
	int		size;

	temp = *stack;
	low = temp->value;
	size = temp->size;
	if (size < 2)
		return (SUCCESS);
	while (--size > 0)
	{
		temp = temp->next;
		if (low > temp->value)
			return (ERROR);
		low = temp->value;
	}
	return (SUCCESS);
}

int	is_in_order(t_stack	**stack)
{
	t_stack	*temp;
	int		i;
	int		low;

	temp = (*stack)->next;
	low = (*stack)->index;
	i = (*stack)->size;
	while (--i > 0)
	{
		if (temp->index < low)
			low = temp->index;
		temp = temp->next;
	}
	i = (*stack)->size;
	while (temp->index != low)
		temp = temp->next;
	while (--i > 0)
	{
		if (temp->next->index == temp->index + 1)
			temp = temp->next;
		else
			return (ERROR);
	}
	return (SUCCESS);
}

int	get_lowest(t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		low;

	if ((*stack)->size == 0)
		return (0);
	i = (*stack)->size;
	temp = *stack;
	low = temp->index;
	while (--i > 0)
	{
		temp = temp->next;
		if (temp->index < low)
			low = temp->index;
	}
	return (low);
}

t_stack	*get_highest(t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		high;

	if ((*stack)->size == 0)
		return (0);
	i = (*stack)->size;
	temp = *stack;
	high = temp->index;
	while (--i > 0)
	{
		temp = temp->next;
		if (temp->index > high)
			high = temp->index;
	}
	while (temp->index != high)
		temp = temp->next;
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:46:54 by araymond          #+#    #+#             */
/*   Updated: 2023/05/04 10:36:18 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void	push_empty(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*end_from;

	free(*stack_to);
	end_from = (*stack_from)->prev;
	*stack_to = *stack_from;
	*stack_from = (*stack_from)->next;
	(*stack_from)->size = (*stack_to)->size - 1;
	(*stack_from)->prev = end_from;
	end_from->next = *stack_from;
	(*stack_to)->size = 1;
	(*stack_to)->next = (*stack_to);
	(*stack_to)->prev = (*stack_to);
}

static void	push_create(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*end_to;
	t_stack	*temp;

	temp = *stack_from;
	end_to = (*stack_to)->prev;
	temp->size = (*stack_to)->size + 1;
	temp->prev = end_to;
	temp->next = (*stack_to);
	(*stack_to)->prev = temp;
	end_to->next = temp;
	*stack_to = (*stack_to)->prev;
	*stack_from = initiate_stack();
	if (!*stack_from)
		error_message(stack_to, NULL, NULL);
}

static void	push_stack(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*end_from;
	t_stack	*end_to;
	t_stack	*temp;

	temp = *stack_from;
	end_from = temp->prev;
	end_to = (*stack_to)->prev;
	*stack_from = (*stack_from)->next;
	(*stack_from)->size = temp->size - 1;
	temp->size = (*stack_to)->size + 1;
	temp->prev = end_to;
	temp->next = *stack_to;
	(*stack_to)->prev = temp;
	end_to->next = temp;
	*stack_to = (*stack_to)->prev;
	end_from->next = *stack_from;
	(*stack_from)->prev = end_from;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->size < 1)
		return ;
	if ((*stack_b)->size == 1)
		push_create(stack_b, stack_a);
	else if ((*stack_b)->size > 1)
	{
		if ((*stack_a)->size == 0)
			push_empty(stack_b, stack_a);
		else
			push_stack(stack_b, stack_a);
	}
	write(STDOUT_FILENO, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size < 1)
		return ;
	if ((*stack_a)->size == 1)
		push_create(stack_a, stack_b);
	else if ((*stack_a)->size > 1)
	{
		if ((*stack_b)->size == 0)
			push_empty(stack_a, stack_b);
		else
			push_stack(stack_a, stack_b);
	}
	write(STDOUT_FILENO, "pb\n", 3);
}

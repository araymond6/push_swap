/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:57:42 by araymond          #+#    #+#             */
/*   Updated: 2023/04/22 13:27:56 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	swap_exception(t_stack **stack)
{
	(*stack) = (*stack)->next;
	(*stack)->size = (*stack)->next->size;
}

void	swap_a(t_stack **stack, int both)
{
	t_stack	*end;
	t_stack	*next;
	t_stack	*move;

	if ((*stack)->size < 2)
		return ;
	if ((*stack)->size == 2)
		swap_exception(stack);
	else
	{
		end = (*stack)->prev;
		move = (*stack)->next;
		next = move->next;
		(*stack)->next = next;
		(*stack)->prev = move;
		move->next = *stack;
		move->prev = end;
		end->next = move;
		next->prev = *stack;
		*stack = (*stack)->prev;
		(*stack)->size = (*stack)->next->size;
	}	
	if (both == 0)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_b(t_stack **stack, int both)
{
	t_stack	*end;
	t_stack	*next;
	t_stack	*move;

	if ((*stack)->size < 2)
		return ;
	if ((*stack)->size == 2)
		swap_exception(stack);
	else
	{
		end = (*stack)->prev;
		move = (*stack)->next;
		next = move->next;
		(*stack)->next = next;
		(*stack)->prev = move;
		move->next = *stack;
		move->prev = end;
		end->next = move;
		next->prev = *stack;
		*stack = (*stack)->prev;
		(*stack)->size = (*stack)->next->size;
	}	
	if (both == 0)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	write(STDOUT_FILENO, "ss\n", 3);
}

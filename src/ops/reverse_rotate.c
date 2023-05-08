/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:42:56 by araymond          #+#    #+#             */
/*   Updated: 2023/04/28 12:05:24 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	reverse_rotate_a(t_stack **stack, int both)
{
	*stack = (*stack)->prev;
	(*stack)->size = (*stack)->next->size;
	if (both == 0)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack, int both)
{
	*stack = (*stack)->prev;
	(*stack)->size = (*stack)->next->size;
	if (both == 0)
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a, 1);
	reverse_rotate_b(stack_b, 1);
	write(STDOUT_FILENO, "rrr\n", 4);
}

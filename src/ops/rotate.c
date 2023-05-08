/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:10:22 by araymond          #+#    #+#             */
/*   Updated: 2023/04/20 16:17:25 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	rotate_a(t_stack **stack, int both)
{
	*stack = (*stack)->next;
	(*stack)->size = (*stack)->prev->size;
	if (both == 0)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rotate_b(t_stack **stack, int both)
{
	*stack = (*stack)->next;
	(*stack)->size = (*stack)->prev->size;
	if (both == 0)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
	write(STDOUT_FILENO, "rr\n", 3);
}

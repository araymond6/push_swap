/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:46:49 by araymond          #+#    #+#             */
/*   Updated: 2023/05/04 10:36:00 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	start_process(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = initiate_stack();
	if (!stack_b)
		error_message(stack_a, NULL, NULL);
	if (is_sorted(stack_a) == SUCCESS)
		return ;
	if ((*stack_a)->size <= 3)
		small_sort(stack_a, &stack_b);
	else if ((*stack_a)->size >= 4 && (*stack_a)->size <= 5)
		medium_sort(stack_a, &stack_b);
	else if ((*stack_a)->size >= 6)
		large_sort(stack_a, &stack_b);
	clear_stack(stack_a);
	clear_stack(&stack_b);
}

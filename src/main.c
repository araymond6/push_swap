/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:17:37 by araymond          #+#    #+#             */
/*   Updated: 2023/05/04 10:34:33 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	error_message(t_stack **stack_a, t_stack **stack_b, char **split)
{
	if (stack_a)
		clear_stack(stack_a);
	if (stack_b)
		clear_stack(stack_b);
	if (split)
		free_2d(split);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc > 2)
	{
		stack_a = initiate_stack();
		if (!stack_a)
			error_message(NULL, NULL, NULL);
		parse_args(argc, argv, &stack_a);
	}
	else if (argc == 2)
	{
		stack_a = initiate_stack();
		if (!stack_a)
			error_message(NULL, NULL, NULL);
		parse_exception(argv, &stack_a);
	}
	return (EXIT_SUCCESS);
}

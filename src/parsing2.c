/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:27:45 by araymond          #+#    #+#             */
/*   Updated: 2023/05/04 11:44:02 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ops.h"

void	index_loop(t_stack	**temp, int *low)
{
	if ((*temp)->value < *low)
		*low = (*temp)->value;
	*temp = (*temp)->next;
}

void	parse_loop(t_stack **stack, t_stack **temp, t_stack *prev)
{
	addback_stack(stack);
	prev = *temp;
	*temp = (*temp)->next;
	(*temp)->prev = prev;
	prev->next = *temp;
}

void	parse_exception(char **argv, t_stack **stack)
{
	int		i;
	t_stack	*temp;
	t_stack	*prev;
	char	**split;

	temp = *stack;
	prev = NULL;
	i = 0;
	split = ft_split(argv[1], ' ');
	if (split == NULL)
		error_message(stack, NULL, NULL);
	while (split[i])
	{
		if (check_args(&temp, split[i], split) == ERROR)
			error_message(stack, NULL, split);
		(*stack)->size++;
		if (!(split[i + 1] == NULL))
			parse_loop(stack, &temp, prev);
		i++;
	}
	check_eq(stack, split);
	set_loop(stack, i);
	free_2d(split);
	start_process(stack);
}

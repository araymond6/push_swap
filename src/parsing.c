/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:05:18 by araymond          #+#    #+#             */
/*   Updated: 2023/05/04 11:43:15 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ops.h"

void	check_eq(t_stack **stack, char **split)
{
	t_stack	*first;
	t_stack	*temp;

	first = *stack;
	while (first->next != NULL)
	{
		temp = first->next;
		while (temp)
		{
			if (first->value == temp->value)
				error_message(stack, NULL, split);
			temp = temp->next;
		}
		first = first->next;
	}
}

void	set_index(t_stack **stack, int s_count)
{
	t_stack	*temp;
	int		i;
	int		low;
	int		index;

	temp = (*stack);
	i = temp->size;
	low = temp->value;
	index = 1;
	while (--i >= 0)
		index_loop(&temp, &low);
	while (index <= s_count)
	{
		i = (*stack)->size;
		temp = (*stack);
		while (--i >= 0)
		{
			if (temp->value == low)
				temp->index = index++;
			temp = temp->next;
		}
		low++;
	}
}

void	set_loop(t_stack **stack, int s_count)
{
	t_stack	*last;

	last = *stack;
	while (!(last->next == NULL))
	{
		last->size = s_count;
		last = last->next;
	}
	last->size = s_count;
	last->next = *stack;
	(*stack)->prev = last;
	set_index(stack, s_count);
}

int	check_args(t_stack **stack, char *str, char **split)
{
	int			i;
	long long	nb;
	t_stack		*temp;

	if (ft_strlen(str) > 11)
		error_message(stack, NULL, split);
	temp = *stack;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && i == 0)
			i++;
		if (!ft_isdigit(str[i]))
			return (ERROR);
		i++;
	}
	nb = long_atoi(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (ERROR);
	temp->value = (int)nb;
	return (SUCCESS);
}

void	parse_args(int argc, char **argv, t_stack **stack)
{
	int		i;
	t_stack	*temp;
	t_stack	*prev;

	temp = *stack;
	prev = NULL;
	i = 0;
	while (argv[++i])
	{
		if (check_args(&temp, argv[i], NULL) == ERROR)
			error_message(stack, NULL, NULL);
		(*stack)->size++;
		if (!(argv[i + 1] == NULL))
			parse_loop(stack, &temp, prev);
	}
	check_eq(stack, NULL);
	set_loop(stack, argc - 1);
	start_process(stack);
}

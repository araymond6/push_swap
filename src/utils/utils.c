/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:53:56 by araymond          #+#    #+#             */
/*   Updated: 2023/05/04 11:35:38 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_2d(char **strstr)
{
	int	i;

	i = 0;
	while (strstr[i])
	{
		free(strstr[i]);
		i++;
	}
	free(strstr);
}

t_stack	*initiate_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = 0;
	stack->size = 0;
	stack->index = 0;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = (*stack)->size;
	temp = *stack;
	if ((*stack)->size == 0)
	{
		free(*stack);
		return ;
	}
	else
	{
		while (--i > 0)
		{
			*stack = (*stack)->next;
			free(temp);
			temp = *stack;
		}
		free(*stack);
	}
}

int	addback_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	temp = *stack;
	while (!(temp->next == NULL))
		temp = temp->next;
	next = initiate_stack();
	if (!next)
	{
		clear_stack(stack);
		return (ERROR);
	}
	temp->next = next;
	next->prev = *stack;
	return (SUCCESS);
}

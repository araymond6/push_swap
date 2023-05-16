/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:18:35 by araymond          #+#    #+#             */
/*   Updated: 2023/05/16 09:38:35 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "../libft/src/libft.h"

# define ERROR 0
# define SUCCESS 1

typedef struct s_stack
{
	int				value;
	int				size;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// Sorting
void	start_process(t_stack **stack_a);
void	small_sort(t_stack **stack_a, t_stack **stack_b);
void	medium_sort(t_stack **stack_a, t_stack **stack_b);
void	large_sort(t_stack **stack_a, t_stack **stack_b);

// Parsing
void	parse_args(int argc, char **argv, t_stack **stack);
void	parse_exception(char **argv, t_stack **stack);
void	index_loop(t_stack	**temp, int *low);
void	check_eq(t_stack **stack, char **split);
void	set_index(t_stack **stack, int s_count);
int		check_args(t_stack **stack, char *str, char **split);
void	set_loop(t_stack **stack, int s_count);
void	parse_loop(t_stack **stack, t_stack **temp, t_stack *prev, \
		char **split);

#endif
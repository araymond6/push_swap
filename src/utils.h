/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:56:19 by araymond          #+#    #+#             */
/*   Updated: 2023/05/04 13:05:27 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

// Utils
void		error_message(t_stack **stack_a, t_stack **stack_b, char **split);
t_stack		*initiate_stack(void);
void		clear_stack(t_stack **stack);
int			addback_stack(t_stack **stack);
long long	long_atoi(const char *str);
void		free_2d(char **strstr);

// Sort Utils
int			is_sorted(t_stack **stack);
int			is_faster(t_stack **stack, t_stack *temp);
int			is_in_order(t_stack	**stack);
int			get_lowest(t_stack **stack);
t_stack		*get_highest(t_stack **stack);

#endif
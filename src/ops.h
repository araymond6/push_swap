/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:10:57 by araymond          #+#    #+#             */
/*   Updated: 2023/05/04 11:33:19 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include "push_swap.h"

// Operations
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack, int both);
void	reverse_rotate_b(t_stack **stack, int both);
void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack, int both);
void	rotate_b(t_stack **stack, int both);
void	rotate_r(t_stack **stack_a, t_stack **stack_b);
void	swap_a(t_stack **stack_a, int both);
void	swap_b(t_stack **stack_b, int both);
void	swap_s(t_stack **stack_a, t_stack **stack_b);

#endif
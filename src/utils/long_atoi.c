/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:45:44 by araymond          #+#    #+#             */
/*   Updated: 2023/04/05 11:23:02 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

long long	long_atoi(const char *str)
{
	int			i;
	int			j;
	long long	nb;

	i = 0;
	j = 0;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (j)
		return (-nb);
	return (nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:55:42 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/23 13:28:05 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	first;
	int	i;
	int	res;
	int	neg;

	first = 0;
	while ((str[first] > 7 && str[first] < 14) || str[first] == 32)
		first++;
	i = first;
	res = 0;
	neg = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') ||
				(i == first && (str[i] == '-' || str[i] == '+'))))
	{
		if (str[i] == '-')
			neg = 1;
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (neg)
		res = res * -1;
	return (res);
}

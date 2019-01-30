/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:36:33 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/19 20:12:57 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *str, char c)
{
	int count;
	int len;

	len = 0;
	count = 0;
	while (*str)
	{
		if (*str == c)
			len = 0;
		else if (++len == 1)
			count++;
		str++;
	}
	return (count);
}

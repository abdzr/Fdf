/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 10:34:26 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/23 12:24:51 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const char		*strr1;
	const char		*strr2;

	i = 0;
	strr1 = (const char *)s1;
	strr2 = (const char *)s2;
	while (i < n)
	{
		if ((unsigned char)strr1[i] != (unsigned char)strr2[i])
			return ((unsigned char)strr1[i] - (unsigned char)strr2[i]);
		i++;
	}
	return (0);
}

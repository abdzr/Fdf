/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:05:24 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/15 12:39:43 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	const char		*srcs;

	dest = (unsigned char *)dst;
	srcs = (const char *)src;
	i = 0;
	while (n > i)
	{
		dest[i] = srcs[i];
		if (dest[i] == (unsigned char)c)
			return ((void *)(dest + i + 1));
		i++;
	}
	return ((void *)0);
}

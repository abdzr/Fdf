/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:12:36 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/30 12:25:21 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	const char	*srcs;
	char		tmp[len];

	i = 0;
	if (len > 65535)
		return (NULL);
	dest = (char *)dst;
	srcs = (const char *)src;
	while (len > i)
	{
		tmp[i] = srcs[i];
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	while (i < len)
	{
		dest[i] = tmp[i];
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:10:28 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/18 16:36:55 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = size + 1;
	mem = (char *)malloc(sizeof(char) * i);
	if (mem == 0)
		return (0);
	ft_memset(mem, 0, i);
	return (mem);
}

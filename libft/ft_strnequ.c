/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:39:56 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/20 12:06:13 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		if (ft_strncmp((char *)s1, (char *)s2, n) == 0)
			return (1);
		if (ft_strncmp((char *)s1, (char *)s2, n) != 0)
			return (0);
	}
	return (0);
}

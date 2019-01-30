/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:49:30 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/20 12:08:20 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (ft_strcmp((char *)s1, (char *)s2) == 0)
			return (1);
		if (ft_strcmp((char *)s1, (char *)s2) != 0)
			return (0);
	}
	return (0);
}

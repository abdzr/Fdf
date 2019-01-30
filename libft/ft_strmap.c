/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:53:59 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/20 12:09:56 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*mem;

	if (s && f)
	{
		mem = (char *)malloc(ft_strlen(s) + 1);
		if (mem == 0)
			return (NULL);
		i = 0;
		while (s[i])
		{
			mem[i] = f(s[i]);
			i++;
		}
		mem[i] = '\0';
		return (mem);
	}
	return (0);
}

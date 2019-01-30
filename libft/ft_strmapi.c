/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:20:58 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/20 12:08:17 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	char			*mem;
	unsigned int	n;

	if (s && f)
	{
		mem = (char *)malloc(ft_strlen(s) + 1);
		if (mem == 0)
			return (NULL);
		i = 0;
		n = 0;
		while (s[i])
		{
			mem[i] = f(n, s[i]);
			i++;
			n++;
		}
		mem[i] = '\0';
		return (mem);
	}
	return (0);
}

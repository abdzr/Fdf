/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:30:18 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/20 12:07:04 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	l1;
	size_t	l2;
	int		i;
	int		j;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		mem = (char *)malloc(l1 + l2 + 1);
		if (mem == 0)
			return (NULL);
		while (s1[j])
			mem[i++] = s1[j++];
		j = 0;
		while (s2[j])
			mem[i++] = s2[j++];
		mem[i] = '\0';
		return (mem);
	}
	return (0);
}

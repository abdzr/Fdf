/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:06:45 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/19 20:34:18 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		len;
	int		i;
	int		j;
	char	**ret;

	if (!s)
		return (0);
	if (!(ret = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = i;
		while (s[i] && s[i] != c)
			i++;
		if (len < i)
			ret[j++] = ft_strndup(s + len, i - len);
	}
	ret[j] = NULL;
	return (ret);
}

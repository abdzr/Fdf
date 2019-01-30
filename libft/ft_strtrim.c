/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:56:36 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/22 10:56:17 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		j;
	int		i;
	size_t	lstr;
	char	*str;

	if (!s)
		return (0);
	lstr = ft_strlen(s) - 1;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (i == (int)ft_strlen(s))
		return (ft_strdup("\0"));
	while (s[lstr] == ' ' || s[lstr] == '\n' || s[lstr] == '\t')
		lstr--;
	str = (char *)malloc(lstr - i + 2);
	if (str == 0)
		return (NULL);
	j = 0;
	while ((int)lstr >= i)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

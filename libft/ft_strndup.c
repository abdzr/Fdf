/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 20:23:46 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/19 21:00:17 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	int		i;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	if (len < n)
		n = len;
	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == 0)
		return (NULL);
	while (s[i] && i < (int)n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

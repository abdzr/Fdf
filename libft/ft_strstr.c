/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:31:19 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/29 17:19:42 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int j;
	int i;

	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[j])
	{
		if (haystack[j] == needle[0])
		{
			i = 1;
			while (needle[i] && haystack[j + i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:09:32 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/23 11:44:32 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	ft_strncpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:12:54 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/18 16:34:07 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				lstr;
	int				i;
	int				nmbrcpy;

	lstr = ft_intlen(n);
	i = 0;
	nmbrcpy = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		nmbrcpy = -n;
	if (!(str = ft_strnew(lstr)))
		return (NULL);
	str[i++] = (nmbrcpy % 10) + 48;
	while ((nmbrcpy = nmbrcpy / 10) != 0)
		str[i++] = (nmbrcpy % 10) + 48;
	if (n < 0)
		*(str + lstr - 1) = '-';
	return (ft_strrev(str));
}

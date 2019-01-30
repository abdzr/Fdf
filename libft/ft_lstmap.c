/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:17:26 by azarzor           #+#    #+#             */
/*   Updated: 2018/10/21 20:45:58 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mem;
	t_list	*tmp;

	mem = (t_list*)malloc(sizeof(t_list));
	mem = f(lst);
	tmp = mem;
	while (lst->next)
	{
		mem->next = f(lst->next);
		mem = mem->next;
		lst = lst->next;
	}
	return (tmp);
}

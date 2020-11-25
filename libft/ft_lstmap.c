/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:09:50 by larlena           #+#    #+#             */
/*   Updated: 2020/11/10 17:09:20 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*buf;

	dst = NULL;
	while (lst != NULL)
	{
		if ((buf = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		ft_lstadd_back(&dst, buf);
		lst = lst->next;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:23:00 by larlena           #+#    #+#             */
/*   Updated: 2020/11/10 17:01:09 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	while (*lst != NULL)
	{
		buf = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buf;
	}
}

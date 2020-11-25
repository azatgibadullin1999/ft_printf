/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:34:19 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 15:35:53 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*buf;

	i = 0;
	buf = (unsigned char *)b;
	while (i < len)
	{
		buf[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

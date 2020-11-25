/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:39:01 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 16:40:35 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	i = 0;
	buf1 = (unsigned char *)dst;
	buf2 = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		buf1[i] = buf2[i];
		i++;
	}
	return (buf1);
}

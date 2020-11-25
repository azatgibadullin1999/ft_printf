/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:50:08 by larlena           #+#    #+#             */
/*   Updated: 2020/11/10 10:33:49 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf1;
	unsigned char	*buf2;

	buf1 = (unsigned char *)dst;
	buf2 = (unsigned char *)src;
	if (len == 0)
		return (dst);
	if (src > dst)
		ft_memcpy(dst, src, len);
	if (src < dst)
	{
		len--;
		while (len > 0)
		{
			buf1[len] = buf2[len];
			len--;
		}
		buf1[len] = buf2[len];
	}
	return (dst);
}

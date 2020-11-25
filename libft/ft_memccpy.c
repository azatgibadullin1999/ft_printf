/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:42:45 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 16:37:35 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	i = 0;
	buf1 = (unsigned char *)dst;
	buf2 = (unsigned char *)src;
	while (i < n)
	{
		buf1[i] = buf2[i];
		if (buf2[i] == (unsigned char)c)
			return ((void *)&buf1[i + 1]);
		i++;
	}
	return (NULL);
}

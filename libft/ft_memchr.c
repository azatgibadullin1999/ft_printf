/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:32:00 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 16:38:22 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*buf;

	i = 0;
	buf = (unsigned const char *)s;
	while (i < n)
	{
		if (buf[i] == (unsigned char)c)
			return ((void *)&buf[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:26:04 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 16:39:17 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	i = 0;
	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	while (i < n)
	{
		if (buf1[i] - buf2[i] != 0)
			return (buf1[i] - buf2[i]);
		i++;
	}
	return (0);
}

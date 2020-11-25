/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:57:51 by larlena           #+#    #+#             */
/*   Updated: 2020/11/11 19:12:39 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;
	size_t	i;

	i = 0;
	start = 0;
	while (dst[start] != '\0' && start < dstsize)
		start++;
	while (start + i + 1 < dstsize && src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
	if (start != dstsize)
		dst[start + i] = '\0';
	return (start + ft_strlen(src));
}

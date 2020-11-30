/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:15:42 by larlena           #+#    #+#             */
/*   Updated: 2020/11/27 19:48:04 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_chr_count(unsigned long long n, int notation)
{
	size_t	i;

	i = 0;
	while (n >= notation)
	{
		n = n / notation;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(unsigned long long n, int notation)
{
	char	*dst;
	size_t	i;

	i = ft_chr_count(n, notation);
	if ((dst = ft_calloc(sizeof(char), i + 1)) == NULL)
		return (NULL);
	i--;
	while (n >= 10)
	{
		dst[i] = n % notation + '0';
		n = n / notation;
		i--;
	}
	dst[i] = n + '0';
	return (dst);
}

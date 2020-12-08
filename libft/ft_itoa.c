/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:15:42 by larlena           #+#    #+#             */
/*   Updated: 2020/12/08 13:25:38 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_chr_count(long long n, int notation)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n >= notation)
	{
		n = n / notation;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(long long n, int notation)
{
	char	*dst;
	size_t	i;

	i = ft_chr_count(n, notation);
	if ((dst = ft_calloc(sizeof(char), i + 1)) == NULL)
		return (NULL);
	i--;
	if (n < 0)
	{
		dst[0] = '-';
		n = n * -1;
	}
	while (n >= notation)
	{
		dst[i] = n % notation + '0';
		n = n / notation;
		i--;
	}
	dst[i] = n + '0';
	return (dst);
}

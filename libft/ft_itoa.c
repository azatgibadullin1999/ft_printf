/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:15:42 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 16:36:50 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_chr_count(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*dst;
	size_t	i;

	i = ft_chr_count(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((dst = ft_calloc(sizeof(char), i + 1)) == NULL)
		return (NULL);
	i--;
	if (n < 0)
	{
		n = n * -1;
		dst[0] = '-';
	}
	while (n >= 10)
	{
		dst[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	dst[i] = n + '0';
	return (dst);
}

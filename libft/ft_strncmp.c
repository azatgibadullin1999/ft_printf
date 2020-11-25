/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:59:52 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 16:52:25 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	size_t			i;

	i = 0;
	buf1 = (unsigned char *)str1;
	buf2 = (unsigned char *)str2;
	while (i < n && buf1[i] && buf2[i])
	{
		if (buf1[i] - buf2[i] != 0)
			return (buf1[i] - buf2[i]);
		i++;
	}
	if ((buf1[i] == '\0' || buf2[i] == '\0') && i != n)
		return (buf1[i] - buf2[i]);
	return (0);
}

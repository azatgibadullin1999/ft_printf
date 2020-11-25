/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:47:55 by larlena           #+#    #+#             */
/*   Updated: 2020/11/11 18:26:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0 && *str2 != '\0')
		return (NULL);
	if (*str2 == '\0' || str2 == NULL)
		return ((char *)str1);
	while (str1[i] && i < len)
	{
		j = 0;
		while (i < len && str1[i] && str2[j] && (str1[i] == str2[j]))
		{
			i++;
			j++;
		}
		if (str2[j] == '\0')
			return ((char *)&str1[i - j]);
		i = i - j;
		i++;
	}
	return (NULL);
}

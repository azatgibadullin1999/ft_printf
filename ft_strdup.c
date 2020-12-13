/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:43:09 by larlena           #+#    #+#             */
/*   Updated: 2020/12/13 18:14:53 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	end;
	size_t	i;

	i = 0;
	end = ft_strlen(s1) + 1;
	if ((dst = ft_calloc(sizeof(char), end)) == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, end + 1);
	return (dst);
}

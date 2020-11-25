/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:17:37 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 16:57:59 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	j = ft_strlen(s1) - 1;
	while (j > 0 && ft_strchr(set, s1[j]) != NULL)
		j--;
	if (j < i)
		return (ft_strdup(""));
	if ((dst = ft_calloc(sizeof(char), j - i + 2)) == NULL)
		return (NULL);
	ft_strlcpy(dst, &s1[i], j - i + 2);
	return (dst);
}

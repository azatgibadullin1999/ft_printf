/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:29:22 by larlena           #+#    #+#             */
/*   Updated: 2020/11/10 13:13:46 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_free(char **dst, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(dst[i]);
		i++;
	}
	free(dst);
	return (NULL);
}

size_t	ft_castom_strlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i + 1);
}

char	**ft_for_normm(char **dst, char const *s, char c)
{
	int		f;
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	i = 0;
	f = 0;
	while (s[i])
	{
		if (f == 0 && s[i] != c)
		{
			len = ft_castom_strlen(&s[i], c);
			if ((dst[j] = ft_calloc(sizeof(char), len)) == NULL)
				return (ft_array_free(dst, j));
			ft_strlcpy(dst[j], &s[i], len);
			j++;
			f = 1;
		}
		if (s[i] == c)
			f = 0;
		i++;
	}
	return (dst);
}

size_t	ft_word_count(char const *s, char c)
{
	int		f;
	size_t	i;
	size_t	count;

	i = 0;
	f = 0;
	count = 0;
	while (s[i])
	{
		if (f == 0 && s[i] != c)
		{
			f = 1;
			count++;
		}
		if (s[i] == c)
			f = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**dst;

	if (s == NULL)
		return (NULL);
	count = ft_word_count(s, c);
	if ((dst = (char **)ft_calloc(sizeof(char *), count + 1)) == NULL)
		return (NULL);
	if (ft_for_normm(dst, s, c) == NULL)
		return (NULL);
	return (dst);
}

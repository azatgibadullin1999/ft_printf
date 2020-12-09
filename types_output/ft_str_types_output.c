/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_types_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:27:56 by larlena           #+#    #+#             */
/*   Updated: 2020/12/09 16:53:36 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*ft_str_creation(char *str, t_printf *all)
{
	size_t	str_size;
	size_t	dst_size;
	char	*dst;

	str_size = all->f_dot && ft_strlen(str) > all->presigion ?
	all->presigion : ft_strlen(str);
	dst_size = str_size > all->width ? str_size : all->width;
	if (!(dst = malloc(sizeof(char) * (dst_size + 1))))
		return (NULL);
	dst[dst_size] = '\0';
	ft_memset(dst, ' ', dst_size);
	if (all->f_minus)
		ft_memcpy(dst, str, str_size);
	else
		ft_memcpy(&dst[dst_size - str_size], str, str_size);
	return (dst);
}

static int		ft_check_null(char **str)
{
	if (*str)
		return (0);
	else
	{
		*str = ft_strdup("(null)");
		return (1);
	}
}

int				ft_str_types_output(char *str, t_printf *all)
{
	int		f_null;
	char	*dst;

	f_null = ft_check_null(&str);
	if (!(dst = ft_str_creation(str, all)))
		return (1);
	ft_putstr_fd(dst, FD_TERM);
	if (f_null)
		free(str);
	free(dst);
	return (0);
}

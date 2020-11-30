/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_types_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:27:56 by larlena           #+#    #+#             */
/*   Updated: 2020/11/27 20:35:25 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_str_types_output(char *str, t_printf *all)
{
	size_t	i;
	size_t	dst_size;
	size_t	str_size;
	char	*dst;

	i = 0;
	if (!str)

	str_size = all->f_dot ? all->presigion : ft_strlen(str);
	dst_size = str_size > all->width ? str_size : all->width;
	if (!(dst = malloc(sizeof(char) * (dst_size + 1))))
		return (1);
	dst[dst_size] = '\0';
	ft_memset(dst, ' ', dst_size);
	if (all->f_minus)
		ft_memcpy(dst, str, str_size);
	else
		ft_memcpy(&dst[dst_size - str_size], str, str_size);
	ft_putstr_fd(dst, FD_TERM);
	free(dst);
	return (0);
}

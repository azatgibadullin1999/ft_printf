/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:30:17 by larlena           #+#    #+#             */
/*   Updated: 2020/12/14 14:44:25 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent_output(t_printf *all)
{
	char	*dst;

	if (!all->width)
		all->width = 1;
	if (!(dst = malloc(sizeof(char) * (all->width + 1))))
		return (1);
	dst[all->width] = '\0';
	if (all->f_minus)
	{
		ft_memset(dst, ' ', all->width);
		*dst = '%';
	}
	else
	{
		if (all->f_zero)
			ft_memset(dst, '0', all->width);
		else
			ft_memset(dst, ' ', all->width);
		dst[all->width - 1] = '%';
	}
	ft_putstr_fd(dst, FD_TERM);
	all->str_size += ft_strlen(dst);
	return (0);
}

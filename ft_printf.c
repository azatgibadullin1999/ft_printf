/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:09:38 by larlena           #+#    #+#             */
/*   Updated: 2020/12/14 12:57:57 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	all;

	all.i = 0;
	all.str_size = 0;
	va_start(all.ap, format);
	while (format[all.i])
	{
		if (format[all.i] == '%')
		{
			all.i++;
			ft_zeroing_struct(&all);
			ft_parser(format, &all);
		}
		else
		{
			ft_putchar_fd(format[all.i], FD_TERM);
			all.str_size++;
		}
		all.i++;
	}
	return (all.str_size);
}

int		ft_zeroing_struct(t_printf *all)
{
	all->f_minus = 0;
	all->f_zero = 0;
	all->f_dot = 0;
	all->presigion = 0;
	all->width = 0;
	return (0);
}

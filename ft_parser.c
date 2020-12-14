/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:03:10 by larlena           #+#    #+#             */
/*   Updated: 2020/12/14 13:31:27 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arg_type_parsing(const char *format, t_printf *all)
{
	if (format[all->i] == 'c')
		return (ft_char_types_output(va_arg(all->ap, int), all));
	else if (format[all->i] == 's')
		return (ft_str_types_output(va_arg(all->ap, char *), all));
	else if (format[all->i] == 'p')
		return (ft_pointer_types_output(va_arg(all->ap, void *), all));
	else if (format[all->i] == 'd')
		return (ft_int_types_output(va_arg(all->ap, int), all));
	else if (format[all->i] == 'i')
		return (ft_int_types_output(va_arg(all->ap, int), all));
	else if (format[all->i] == 'u')
		return (ft_unsigned_types_output(va_arg(all->ap, unsigned int), all));
	else if (format[all->i] == 'x')
		return (ft_hex_types_output(va_arg(all->ap, unsigned int), 0, all));
	else if (format[all->i] == 'X')
		return (ft_hex_types_output(va_arg(all->ap, unsigned int), 1, all));
	else if (format[all->i] == '%')
	{
		ft_putchar_fd('%', FD_TERM);
		return (0);
	}
	else
		return (1);
}

int		ft_presigions_parsing(const char *format, t_printf *all)
{
	if (format[all->i] == '.')
	{
		all->i++;
		if (ft_isdigit(format[all->i]))
		{
			all->presigion = ft_atoi(&format[all->i]);
			while (ft_isdigit(format[all->i]))
				all->i++;
		}
		else if (format[all->i] == '*')
		{
			all->presigion = va_arg(all->ap, int);
			all->i++;
		}
		if (all->presigion >= 0)
			all->f_dot = 1;
	}
	return (0);
}

int		ft_widths_parsing(const char *format, t_printf *all)
{
	if (ft_isdigit(format[all->i]))
	{
		all->width = ft_atoi(&format[all->i]);
		while (ft_isdigit(format[all->i]))
			all->i++;
	}
	else if (format[all->i] == '*')
	{
		all->width = va_arg(all->ap, int);
		all->i++;
	}
	if (all->width < 0)
	{
		all->f_minus = 1;
		all->f_zero = 0;
		all->width *= -1;
	}
	return (0);
}

int		ft_flags_parsing(const char *format, t_printf *all)
{
	while (format[all->i] && (format[all->i] == '-' || format[all->i] == '0'))
	{
		if (format[all->i] == '-')
			all->f_minus = 1;
		if (format[all->i] == '0')
			all->f_zero = 1;
		all->i++;
	}
	return (0);
}

int		ft_parser(const char *format, t_printf *all)
{
	if (ft_flags_parsing(format, all))
		return (1);
	ft_widths_parsing(format, all);
	ft_presigions_parsing(format, all);
	if (ft_arg_type_parsing(format, all))
		return (1);
	return (0);
}

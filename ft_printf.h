/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:51:31 by larlena           #+#    #+#             */
/*   Updated: 2020/11/26 00:15:23 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define FD_TERM 1

typedef struct	s_pritnf
{
	va_list		ap;
	size_t		i;
	size_t		str_size;
	int			f_minus;
	int			f_zero;
	int			width;
	int			presigion;
}				t_printf;

int				ft_printf(const char *format, ...);
int				ft_zeroing_struct(t_printf *all);
int				ft_parser(const char *format, t_printf *all);
int				ft_flags_parsing(const char *format, t_printf *all);
int				ft_widths_parsing(const char *format, t_printf *all);
int				ft_presigions_parsing(const char *format, t_printf *all);
int				ft_arg_type_parsing(const char *format, t_printf *all);
int				ft_c_types_output(int c, t_printf *all);

#endif
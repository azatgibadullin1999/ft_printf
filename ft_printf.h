/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:51:31 by larlena           #+#    #+#             */
/*   Updated: 2020/12/14 13:16:41 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define FD_TERM 1

typedef struct	s_pritnf
{
	va_list		ap;
	size_t		i;
	size_t		str_size;
	size_t		num_len;
	int			f_minus;
	int			f_zero;
	int			f_dot;
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
int				ft_char_types_output(int c, t_printf *all);
int				ft_str_types_output(char *str, t_printf *all);
int				ft_pointer_types_output(void *p, t_printf *all);
int				ft_int_types_output(int n, t_printf *all);
int				ft_hex_types_output(unsigned int n, int reg, t_printf *all);
int				ft_unsigned_types_output(unsigned int n, t_printf *all);

int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
int				ft_isdigit(int c);
char			*ft_itoa(long long n, int notation);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
int				ft_toupper(int c);

#endif

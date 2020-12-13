/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_types_output.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:06:40 by larlena           #+#    #+#             */
/*   Updated: 2020/12/13 16:08:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_castom_putstr_fd(char *str, int fd, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

int				ft_char_types_output(int c, t_printf *all)
{
	size_t	ar_size;
	char	*str;

	ar_size = all->width ? all->width : 1;
	if (!(str = malloc(sizeof(char) * (ar_size + 1))))
		return (1);
	str[ar_size] = '\0';
	ft_memset(str, ' ', ar_size);
	if (all->f_minus)
	{
		str[0] = c;
		ft_castom_putstr_fd(str, FD_TERM, ar_size);
	}
	else
	{
		str[ar_size - 1] = (char)c;
		ft_castom_putstr_fd(str, FD_TERM, ar_size);
	}
	free(str);
	return (0);
}

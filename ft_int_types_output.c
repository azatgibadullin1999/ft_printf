/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_types_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:17:49 by larlena           #+#    #+#             */
/*   Updated: 2020/12/14 15:18:27 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_insert_minus(char *dst)
{
	size_t	i;

	i = 0;
	while (!ft_isdigit(dst[i]))
		i++;
	dst[i] = '-';
}

static void		ft_filling_array(char *dst, char *num, t_printf *all)
{
	size_t	num_size;
	size_t	dst_size;
	int		f_minus;

	dst_size = ft_strlen(dst);
	f_minus = *num == '-' ? 1 && num++ : 0;
	num_size = all->presigion > (int)ft_strlen(num) ?
	all->presigion : ft_strlen(num);
	num_size += f_minus;
	if (all->f_minus && all->width)
	{
		ft_memset(dst, '0', num_size);
		ft_memcpy(&dst[num_size - ft_strlen(num)], num, ft_strlen(num));
	}
	else
	{
		ft_memset(&dst[dst_size - num_size], '0', num_size);
		ft_memcpy(&dst[dst_size - ft_strlen(num)], num, ft_strlen(num));
	}
	if (f_minus)
		ft_insert_minus(dst);
}

static char		*ft_counting_dst_len(char *num, t_printf *all)
{
	char	*dst;
	size_t	dst_len;
	size_t	len;

	len = ft_strlen(num);
	dst_len = (int)len > all->presigion ? len : all->presigion;
	dst_len = all->width > (int)dst_len ? all->width : dst_len;
	dst_len += all->presigion > all->width &&
	(int)len <= all->presigion && *num == '-' ? 1 : 0;
	if (!(dst = malloc(sizeof(char) * (dst_len + 1))))
		return (NULL);
	dst[dst_len] = '\0';
	if (all->f_zero && all->width && all->presigion < all->width && !all->f_dot)
		ft_memset(dst, '0', dst_len);
	else
		ft_memset(dst, ' ', dst_len);
	return (dst);
}

int				ft_int_types_output(int n, t_printf *all)
{
	char	*num;
	char	*dst;
	char	*tmp;

	if (!(num = ft_itoa(n, 10)))
		return (1);
	if (!(dst = ft_counting_dst_len(num, all)))
	{
		free(num);
		return (1);
	}
	ft_filling_array(dst, num, all);
	if (all->f_dot && !all->presigion && !n)
	{
		tmp = ft_strchr(dst, '0');
		*tmp = !all->width ? '\0' : ' ';
	}
	ft_putstr_fd(dst, FD_TERM);
	all->str_size += ft_strlen(dst);
	free(num);
	free(dst);
	return (0);
}

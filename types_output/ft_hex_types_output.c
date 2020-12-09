/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_types_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:18:10 by larlena           #+#    #+#             */
/*   Updated: 2020/12/09 14:45:16 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_str_toupper(char *dst)
{
	size_t	i;

	i = 0;
	while (dst[i])
	{
		dst[i] = ft_toupper(dst[i]);
		i++;
	}
}

static void		ft_filling_array(char *dst, char *num, t_printf *all)
{
	size_t	num_size;
	size_t	dst_size;

	dst_size = ft_strlen(dst);
	num_size = all->presigion > ft_strlen(num) ?
	all->presigion : ft_strlen(num);
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
}

static char		*ft_counting_dst_len(char *num, t_printf *all)
{
	char	*dst;
	size_t	dst_len;
	size_t	len;

	len = ft_strlen(num);
	dst_len = len > all->presigion ? len : all->presigion;
	dst_len = all->width > dst_len ? all->width : dst_len;
	if (!(dst = malloc(sizeof(char) * (dst_len + 1))))
		return (NULL);
	dst[dst_len] = '\0';
	if (all->f_zero && all->width && all->presigion < all->width && !all->f_dot)
		ft_memset(dst, '0', dst_len);
	else
		ft_memset(dst, ' ', dst_len);
	return (dst);
}

static int		ft_convert_to_hex(char **num, unsigned int n)
{
	size_t	i;

	i = 0;
	if (!(*num = ft_itoa(n, 16)))
		return (1);
	while ((*num)[i])
	{
		if (!ft_isdigit((*num)[i]))
			(*num)[i] += 39;
		i++;
	}
	return (0);
}

int				ft_hex_types_output(unsigned int n, int reg, t_printf *all)
{
	char	*dst;
	char	*num;

	if (ft_convert_to_hex(&num, n))
		return (1);
	if (!(dst = ft_counting_dst_len(num, all)))
	{
		free(num);
		return (1);
	}
	ft_filling_array(dst, num, all);
	if (reg)
		ft_str_toupper(dst);
	ft_putstr_fd(dst, FD_TERM);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_types_output.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:42:33 by larlena           #+#    #+#             */
/*   Updated: 2020/12/09 14:47:41 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_convert_to_hex(char **dst, unsigned long p_d)
{
	size_t			i;
	char			*tmp;

	i = 2;
	if (!(tmp = ft_strdup("0x")))
		return (1);
	if (!(*dst = ft_strjoin(tmp, ft_itoa(p_d, 16))))
		return (1);
	while ((*dst)[i])
	{
		if (!ft_isdigit((*dst)[i]))
			(*dst)[i] += 39;
		i++;
	}
	return (0);
}

int				ft_pointer_types_output(void *p, t_printf *all)
{
	unsigned long	p_d;
	size_t			size;
	char			*dst;
	char			*tmp;

	p_d = (unsigned long)p;
	if (ft_convert_to_hex(&dst, p_d))
		return (1);
	size = all->width > ft_strlen(dst) ? all->width : ft_strlen(dst);
	if (!(tmp = malloc(sizeof(char) * (size + 1))))
	{
		free(dst);
		return (1);
	}
	tmp[size] = '\0';
	ft_memset(tmp, ' ', size);
	if (all->f_minus)
		ft_memcpy(tmp, dst, ft_strlen(dst));
	else
		ft_memcpy(&tmp[size - ft_strlen(dst)], dst, ft_strlen(dst));
	ft_putstr_fd(tmp, FD_TERM);
	free(tmp);
	free(dst);
	return (0);
}

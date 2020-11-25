/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_types_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:06:40 by larlena           #+#    #+#             */
/*   Updated: 2020/11/26 00:26:17 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_c_types_output(int c, t_printf *all)
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
		str[ar_size - 1] = (char)c;
		ft_putstr_fd(str, FD_TERM);
		return (0);
	}
	else
	{
		str[0] = c;
		ft_putstr_fd(str, FD_TERM);
		return (0);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_types_output.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:42:33 by larlena           #+#    #+#             */
/*   Updated: 2020/11/27 21:17:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_pointer_types_output(void *p, t_printf *all)
{
	unsigned long	p_d;
	size_t			i;
	char			*dst;
	char			*buf;

	i = 2;
	p_d = (unsigned long)p;
	if (!(dst = ft_strjoin("0x", ft_itoa(p_d, 16))))
		return (1);
	while (dst[i])
	{
		if (!ft_isalnum(dst[i]))
			dst[i] += 39;
		i++;
	}

	return (0);
}
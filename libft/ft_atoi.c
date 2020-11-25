/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:57:58 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 16:30:56 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	dst;

	dst = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == ' ' ||
	str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		dst = dst * 10 + str[i] - '0';
		i++;
	}
	return (dst * sign);
}

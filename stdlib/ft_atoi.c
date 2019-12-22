/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 19:54:21 by mcabrol           #+#    #+#             */
/*   Updated: 2018/11/05 17:32:41 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	num;
	char				sign;

	num = 0;
	sign = 1;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' || *str
			== '\f' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+' && *(str - 1) != '-')
		str++;
	while (ft_isdigit(*str))
		num = num * 10 + *str++ - '0';
	if (num > 9223372036854775807)
		return ((sign == -1) ? 0 : -1);
	return (sign * (int)num);
}

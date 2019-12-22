/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:30:45 by mcabrol           #+#    #+#             */
/*   Updated: 2019/05/28 16:04:07 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n)
{
	int res;

	res = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		++res;
	while (n != 0)
	{
		n /= 10;
		++res;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	size_t	i;
	char	*str;

	i = ft_size(n) - 1;
	if (!(str = ft_strnew(ft_size(n))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:47:26 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/06/27 13:51:25 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t		size(intmax_t n)
{
	intmax_t res;

	res = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		res++;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char				*ft_except(intmax_t n, char *neg)
{
	if (n < -9223372036854775807)
	{
		neg = ft_strdup("-9223372036854775808");
		return (neg);
	}
	if (n == 0)
	{
		neg = ft_strdup("0");
		return (neg);
	}
	return (neg);
}

char				*ft_ltoa(intmax_t n)
{
	int		i;
	char	*str;
	char	*neg;

	i = size(n) - 1;
	neg = NULL;
	if (!(str = ft_strnew(size(n))))
		return (NULL);
	if ((neg = ft_except(n, neg)))
	{
		free(str);
		return (neg);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

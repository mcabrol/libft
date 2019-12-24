/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:42:37 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/09/16 15:56:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_r(int precision, int neg)
{
	double	nbr;

	nbr = 5.0;
	while (precision-- >= 0)
		nbr /= 10;
	return (neg ? -nbr : nbr);
}

char	*ft_partiels(long double ap, int precision)
{
	char	*ret;
	char	c;
	int		i;

	if (!(ret = ft_strnew(precision)))
		return (NULL);
	i = 0;
	while (precision--)
	{
		ap *= 10;
		c = ap;
		ret[i++] = '0' + c;
		ap -= c;
	}
	return (ret);
}

char	*ft_float(long double ap, int precision)
{
	char		*rst;
	char		*rst2;
	long long	intpart;

	if (precision > 0)
		ap += ft_r(precision, ap < 0);
	else
		ap += ft_r(0, ap < 0);
	if (ap < 0)
		ap = -ap;
	intpart = ap;
	ap -= intpart;
	rst = ft_itoa_b(intpart, 10);
	if (precision <= 0)
		return (rst);
	rst2 = ft_partiels(ap, precision);
	ft_strcat(rst, ".");
	ft_strcat(rst, rst2);
	ft_strdel(&rst2);
	return (rst);
}

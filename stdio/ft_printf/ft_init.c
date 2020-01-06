/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:13:14 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/29 19:56:59 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_info		ft_init_tmp(int res, int fullbuffer, int fd)
{
	t_info tmp;

	tmp.fd = fd;
	tmp.res = res;
	tmp.buffer = fullbuffer;
	tmp.hash = 0;
	tmp.plus = 0;
	tmp.minus = 0;
	tmp.space = 0;
	tmp.zero = 0;
	tmp.width = 0;
	tmp.precision = 0;
	tmp.cast = 0;
	tmp.wild = 0;
	tmp.dot = 0;
	tmp.type = 0;
	return (tmp);
}

t_padding	ft_init_padding(void)
{
	t_padding padding;

	padding.start = 0;
	padding.stop = 0;
	padding.zero = 0;
	padding.prefix = 0;
	return (padding);
}

t_sign		ft_init_sign(void)
{
	t_sign sign;

	sign.dd = 0;
	sign.u = 0;
	return (sign);
}

t_info		ft_init_start(int fd)
{
	t_info tmp;

	tmp.fd = fd;
	tmp.buffer = 0;
	tmp.res = 0;
	return (tmp);
}

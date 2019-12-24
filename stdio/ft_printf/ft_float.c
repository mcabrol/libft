/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:22:57 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/18 16:28:55 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_f(t_padding *padding, char *str, char *buff, t_info *tmp)
{
	while (padding->start-- > 0)
		ft_format(' ', buff, tmp);
	ft_strformat(padding->prefix, buff, tmp);
	while (padding->zero-- > 0)
		ft_format('0', buff, tmp);
	ft_strformat(str, buff, tmp);
	if (str != 0)
		ft_strdel(&str);
	while (padding->stop-- > 0)
		ft_format(' ', buff, tmp);
}

void		ft_handle_f(t_padding *padding, t_info *tmp,
		long double f, char *str)
{
	padding->zero = tmp->precision - ft_strlen(str);
	padding->zero < 0 ? padding->zero = 0 : 0;
	padding->start = tmp->width - padding->zero -
		ft_strlen(str) - ft_strlen(padding->prefix);
	padding->start < 0 ? padding->start = 0 : 0;
	if (tmp->plus == 1 && f >= 0)
	{
		padding->prefix = "+";
		padding->start -= ft_strlen(padding->prefix);
	}
	if (tmp->space == 1 && f >= 0 && padding->prefix == 0)
	{
		padding->prefix = " ";
		padding->start -= ft_strlen(padding->prefix);
	}
	if (tmp->minus == 1)
	{
		padding->stop = padding->start;
		padding->start = 0;
	}
	if (tmp->zero == 1)
	{
		padding->zero += padding->start;
		padding->start = 0;
	}
}

long double	ft_cast_f(t_info *tmp, va_list arg)
{
	long double f;

	if (tmp->cast == D)
		f = va_arg(arg, long double);
	else
		f = (double)va_arg(arg, double);
	return (f);
}

void		ft_type_f(va_list arg, t_info *tmp, char *buff)
{
	long double		f;
	char			*str;
	t_padding		padding;

	f = ft_cast_f(tmp, arg);
	padding = ft_init_padding();
	if (tmp->precision < 0)
	{
		str = ft_float(f, 0);
		if (tmp->hash)
			ft_strcat(str, ".");
	}
	else if (tmp->precision)
		str = ft_float(f, tmp->precision);
	else
		str = ft_float(f, 6);
	str = ft_sign(tmp, &padding, str, f);
	if (tmp->type == 'F')
		ft_strtoupper(str);
	ft_handle_f(&padding, tmp, f, str);
	ft_reset_padding(&padding, str);
	ft_print_f(&padding, str, buff, tmp);
}

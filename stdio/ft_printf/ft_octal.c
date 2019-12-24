/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:03:34 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/16 15:10:20 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_print_o(t_padding *padding, char *str,
								char *buff, t_info *tmp)
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

t_padding		ft_handle_o(t_info *tmp, char *str)
{
	t_padding padding;

	padding = ft_init_padding();
	padding.zero = tmp->precision - ft_strlen(str);
	if (padding.zero < 0)
		padding.zero = 0;
	padding.start = tmp->width - padding.zero - ft_strlen(str);
	if (padding.start < 0)
		padding.start = 0;
	if (tmp->hash == 1 && str[0] != '0' && padding.zero == 0)
	{
		padding.prefix = "0";
		padding.start -= ft_strlen(padding.prefix);
	}
	if (tmp->minus == 1)
	{
		padding.stop = padding.start;
		padding.start = 0;
	}
	if (tmp->zero == 1 && tmp->precision == 0)
	{
		padding.zero += padding.start;
		padding.start = 0;
	}
	return (padding);
}

uintmax_t		ft_cast_o(t_info *tmp, va_list arg)
{
	uintmax_t nbr;

	if (tmp->cast == L || tmp->type == 'O')
		nbr = va_arg(arg, unsigned long);
	else if (tmp->cast == LL)
		nbr = va_arg(arg, unsigned long long);
	else if (tmp->cast == H)
		nbr = (unsigned short)va_arg(arg, unsigned int);
	else if (tmp->cast == HH)
		nbr = (unsigned char)va_arg(arg, unsigned int);
	else if (tmp->cast == J)
		nbr = (uintmax_t)va_arg(arg, unsigned long long);
	else if (tmp->cast == Z)
		nbr = (size_t)va_arg(arg, unsigned long long);
	else
		nbr = va_arg(arg, unsigned int);
	return (nbr);
}

void			ft_type_o(va_list arg, t_info *tmp, char *buff)
{
	intmax_t	o;
	char		*str;
	t_padding	padding;

	o = ft_cast_o(tmp, arg);
	if (o == 0 && tmp->precision == -1)
		str = ft_strdup("");
	else
		str = ft_itoa_b(o, 8);
	padding = ft_handle_o(tmp, str);
	return (ft_print_o(&padding, str, buff, tmp));
}

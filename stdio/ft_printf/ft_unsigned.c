/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:15:03 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/16 15:59:32 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_print_u(t_padding *padding, char *str,
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

t_padding		ft_handle_u(t_info *tmp, char *str)
{
	t_padding padding;

	padding = ft_init_padding();
	padding.zero = tmp->precision - ft_strlen(str);
	if (padding.zero < 0)
		padding.zero = 0;
	padding.start = tmp->width - padding.zero - ft_strlen(str) -
		ft_strlen(padding.prefix);
	if (padding.start < 0)
		padding.start = 0;
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

intmax_t		ft_cast_u(t_info *tmp, va_list arg)
{
	intmax_t nbr;

	if (tmp->cast == L || tmp->type == 'U')
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

void			ft_type_u(va_list arg, t_info *tmp, char *buff)
{
	intmax_t	u;
	char		*str;
	t_padding	padding;

	u = ft_cast_u(tmp, arg);
	if (tmp->precision == -1 && u == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_b(u, 10);
	padding = ft_handle_u(tmp, str);
	return (ft_print_u(&padding, str, buff, tmp));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:52:01 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/18 14:00:24 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_x(t_padding *padding, char *str, char *buff, t_info *tmp)
{
	while (padding->start-- > 0)
		ft_format(' ', buff, tmp);
	ft_strformat(padding->prefix, buff, tmp);
	while (padding->zero-- > 0)
		ft_format('0', buff, tmp);
	ft_strformat(str, buff, tmp);
	while (padding->stop-- > 0)
		ft_format(' ', buff, tmp);
}

t_padding	ft_handle_x(t_info *tmp, char *str, int nbr)
{
	t_padding padding;

	padding = ft_init_padding();
	padding.zero = tmp->precision - ft_strlen(str);
	padding.zero < 0 ? padding.zero = 0 : 0;
	padding.start = tmp->width - padding.zero - ft_strlen(str);
	padding.start < 0 ? padding.start = 0 : 0;
	if ((tmp->hash == 1 && nbr != 0) || tmp->type == 'p')
	{
		tmp->type == 'x' || tmp->type == 'p' ? padding.prefix = "0x" : 0;
		tmp->type == 'X' ? padding.prefix = "0X" : 0;
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

intmax_t	ft_cast_x(t_info *tmp, va_list arg)
{
	intmax_t nbr;

	if (tmp->cast != NONE || tmp->type == 'p')
		nbr = va_arg(arg, unsigned long long);
	else
		nbr = (unsigned int)va_arg(arg, unsigned long);
	if (tmp->cast == H)
		nbr = (unsigned short)nbr;
	else if (tmp->cast == HH)
		nbr = (unsigned char)nbr;
	return (nbr);
}

void		ft_type_x(va_list arg, t_info *tmp, char *buff)
{
	int			del;
	intmax_t	x;
	char		*str;
	t_padding	padding;

	del = 0;
	x = ft_cast_x(tmp, arg);
	if (x == 0 || x == 4294967296)
		if (tmp->cast >= 0 && tmp->cast <= 2)
		{
			del++;
			str = "0";
		}
		else
			str = ft_itoa_b(x, 16);
	else if (tmp->type == 'x' || tmp->type == 'p')
		str = ft_itoa_b(x, 16);
	else
		str = ft_strtoupper(ft_itoa_b(x, 16));
	if (tmp->precision == -1 && x == 0)
		str = "";
	padding = ft_handle_x(tmp, str, x);
	ft_print_x(&padding, str, buff, tmp);
	if (!del)
		free(str);
}

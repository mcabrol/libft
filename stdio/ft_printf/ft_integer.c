/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:03:32 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/16 15:10:38 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_d(t_padding *padding, char *str, char *buff, t_info *tmp)
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

void		ft_handle_d(t_padding *padding, t_info *tmp,
		intmax_t nbr, char *str)
{
	padding->zero = tmp->precision - ft_strlen(str);
	padding->zero < 0 ? padding->zero = 0 : 0;
	padding->start = tmp->width - padding->zero - ft_strlen(str) -
		ft_strlen(padding->prefix);
	padding->start < 0 ? padding->start = 0 : 0;
	if (tmp->plus == 1 && nbr >= 0)
	{
		padding->prefix = "+";
		padding->start -= ft_strlen(padding->prefix);
	}
	if (tmp->space == 1 && nbr >= 0 && padding->prefix == 0)
	{
		padding->prefix = " ";
		padding->start -= ft_strlen(padding->prefix);
	}
	if (tmp->minus)
	{
		padding->stop = padding->start;
		padding->start = 0;
	}
	if (tmp->zero == 1 && tmp->precision == 0)
	{
		padding->zero += padding->start;
		padding->start = 0;
	}
}

intmax_t	ft_cast_d(t_info *tmp, va_list arg)
{
	intmax_t nbr;

	if (tmp->cast == L || tmp->type == 'D')
		return (nbr = va_arg(arg, long));
	else if (tmp->cast == LL)
		return (nbr = va_arg(arg, long long));
	else if (tmp->cast == Z)
		return (nbr = va_arg(arg, size_t));
	else if (tmp->cast == J)
		return (nbr = va_arg(arg, intmax_t));
	else if (tmp->cast == H)
		return (nbr = (short)va_arg(arg, int));
	else if (tmp->cast == HH)
		return (nbr = (char)va_arg(arg, int));
	else
		return (nbr = va_arg(arg, int));
}

char		*ft_neg(t_padding *padding, char *str, char *mem, intmax_t di)
{
	if (di < 0)
	{
		padding->prefix = "-";
		mem = str;
		str = ft_strsub(str, 1, ft_strlen(str) - 1);
		ft_strdel(&mem);
	}
	return (str);
}

void		ft_type_d(va_list arg, t_info *tmp, char *buff)
{
	int			del;
	intmax_t	di;
	char		*str;
	t_padding	padding;
	char		*mem;

	ft_wildcard(tmp, arg);
	del = 0;
	mem = NULL;
	di = ft_cast_d(tmp, arg);
	padding = ft_init_padding();
	if (tmp->precision == -1 && di == 0)
		str = "";
	else
	{
		del++;
		str = ft_ltoa(di);
	}
	str = ft_neg(&padding, str, mem, di);
	ft_handle_d(&padding, tmp, di, str);
	ft_print_d(&padding, str, buff, tmp);
	if (del)
		free(str);
}

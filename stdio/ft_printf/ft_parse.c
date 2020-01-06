/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:12:18 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/29 18:58:44 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_parse(const char *format, t_info *tmp, int *i)
{
	if (ft_is_flag(format[*i]))
		ft_parse_flag(format[(*i)++], tmp);
	else if (ft_isdigit(format[*i]))
		tmp->width = ft_parse_precision(format, i);
	else if (tmp->wild && !tmp->precision)
	{
		tmp->width = -1;
		(*i)++;
	}
	else if (format[*i] == '.')
	{
		tmp->dot = 1;
		(*i)++;
		tmp->precision = ft_parse_precision(format, i);
	}
	else if (ft_is_cast(format[*i]))
	{
		tmp->cast = ft_parse_cast(format, i, tmp->cast);
		(*i)++;
	}
}

void		ft_parse_flag(char flag, t_info *tmp)
{
	if (flag == '#')
		tmp->hash = 1;
	else if (flag == '+')
		tmp->plus = 1;
	else if (flag == '-')
		tmp->minus = 1;
	else if (flag == ' ')
		tmp->space = 1;
	else if (flag == '0')
		tmp->zero = 1;
	else if (flag == '*')
		tmp->wild = 1;
}

int			ft_parse_precision(const char *format, int *i)
{
	int		precision;
	int		start;
	char	*str;

	start = *i;
	precision = 0;
	while (ft_isdigit(format[*i]))
		(*i)++;
	str = ft_strsub(format, start, *i - start);
	if (!(precision = ft_atoi(str)))
		precision = -1;
	ft_strdel(&str);
	return (precision);
}

int			ft_parse_cast(const char *format, int *i, int precast)
{
	enum e_cast cast;

	cast = NONE;
	if (format[*i] == 'h')
		cast = H;
	if (format[*i] == 'h' && format[*i + 1] == 'h')
		cast = HH;
	if (format[*i] == 'l')
		cast = L;
	if (format[*i] == 'l' && format[*i + 1] == 'l')
		cast = LL;
	if (format[*i] == 'L')
		cast = D;
	if (format[*i] == 'j')
		cast = J;
	if (format[*i] == 'z')
		cast = Z;
	if (cast == HH || cast == LL)
		(*i)++;
	if (precast > (int)cast)
		return (precast);
	return (cast);
}

void		ft_wildcard(t_info *tmp, va_list arg)
{
	if (tmp->wild)
		tmp->wild = va_arg(arg, int);
	if (tmp->dot == 1)
	{
		if (tmp->precision < tmp->wild)
			tmp->precision = tmp->wild;
		if (tmp->width < tmp->wild)
			tmp->width = tmp->wild;
	}
	else
		tmp->width = tmp->wild;
	tmp->wild = 0;
}

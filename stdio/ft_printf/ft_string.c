/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:56:04 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/16 15:11:58 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_s(t_padding *padding, char *str, char *buff, t_info *tmp)
{
	while (padding->start-- > 0)
		ft_format(' ', buff, tmp);
	while (padding->zero-- > 0)
		ft_format('0', buff, tmp);
	ft_strformat(str, buff, tmp);
	while (padding->stop-- > 0)
		ft_format(' ', buff, tmp);
}

char		*ft_precision_s(t_info *tmp, char *str, int *del)
{
	if (tmp->precision <= (int)ft_strlen(str))
	{
		(*del)++;
		str = ft_strsub(str, 0, tmp->precision);
	}
	if (tmp->precision == -1)
		str = ft_strdup("");
	return (str);
}

t_padding	ft_handle_s(t_info *tmp, char *str)
{
	t_padding padding;

	padding = ft_init_padding();
	padding.start = tmp->width - padding.zero - ft_strlen(str);
	if (padding.start < 0)
		padding.start = 0;
	if (tmp->minus)
	{
		padding.stop = padding.start;
		padding.start = 0;
	}
	if (tmp->zero)
	{
		padding.zero = padding.start;
		padding.start = 0;
	}
	return (padding);
}

void		ft_type_s(va_list arg, t_info *tmp, char *buff)
{
	int			del;
	char		*s;
	t_padding	padding;

	del = 0;
	ft_wildcard(tmp, arg);
	s = (char*)va_arg(arg, long *);
	if (tmp->precision == -1)
		s = "";
	ft_null(tmp, (char**)&s);
	if (tmp->precision && ft_strcmp("", s) != 0)
		s = ft_precision_s(tmp, s, &del);
	padding = ft_handle_s(tmp, s);
	ft_print_s(&padding, s, buff, tmp);
	if (del)
		free(s);
}

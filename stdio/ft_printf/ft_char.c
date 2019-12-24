/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:50:38 by mcabrol           #+#    #+#             */
/*   Updated: 2019/06/20 16:48:34 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_c(int c, t_info *tmp, char *buff)
{
	t_padding	padding;

	padding = ft_handle_c(tmp);
	while (padding.start-- > 0)
		ft_format(' ', buff, tmp);
	while (padding.zero-- > 0)
		ft_format('0', buff, tmp);
	ft_format((char)c, buff, tmp);
	while (padding.stop-- > 0)
		ft_format(' ', buff, tmp);
}

t_padding	ft_handle_c(t_info *tmp)
{
	t_padding	padding;

	padding = ft_init_padding();
	padding.start = tmp->width - 1;
	if (padding.start < 0)
		padding.start = 0;
	if (tmp->minus == 1)
	{
		padding.stop = padding.start;
		padding.start = 0;
	}
	if (tmp->zero == 1)
	{
		padding.zero = padding.start;
		padding.start = 0;
	}
	return (padding);
}

void		ft_type_c(va_list arg, t_info *tmp, char *buff)
{
	int c;

	c = va_arg(arg, int);
	return (ft_print_c(c, tmp, buff));
}

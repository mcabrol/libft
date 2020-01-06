/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:13:44 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/27 19:10:24 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list			arg;
	int				i;
	char			*buff;

	i = 0;
	if ((buff = (char *)malloc(sizeof(char) * BUFFSIZE)) == NULL)
		return (0);
	ft_bzero(buff, BUFFSIZE);
	va_start(arg, format);
	i = ft_start(format, arg, buff, 1);
	va_end(arg);
	return (i);
}

int		ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list			arg;
	int				i;
	char			*buff;

	i = 0;
	if ((buff = (char *)malloc(sizeof(char) * BUFFSIZE)) == NULL)
		return (0);
	ft_bzero(buff, BUFFSIZE);
	va_start(arg, format);
	i = ft_start(format, arg, buff, fd);
	va_end(arg);
	return (i);
}

void	ft_print(va_list arg, t_info *tmp, char *buff)
{
	if (tmp->type == '%')
		return (ft_print_c('%', tmp, buff));
	else if (tmp->type == 'd' || tmp->type == 'i' || tmp->type == 'D')
		return (ft_type_d(arg, tmp, buff));
	else if (tmp->type == 'c' || tmp->type == 'C')
		return (ft_type_c(arg, tmp, buff));
	else if (tmp->type == 's' || tmp->type == 'S')
		return (ft_type_s(arg, tmp, buff));
	else if (tmp->type == 'o' || tmp->type == 'O')
		return (ft_type_o(arg, tmp, buff));
	else if (tmp->type == 'u' || tmp->type == 'U')
		return (ft_type_u(arg, tmp, buff));
	else if (tmp->type == 'x' || tmp->type == 'X' || tmp->type == 'p')
		return (ft_type_x(arg, tmp, buff));
	else if (tmp->type == 'f' || tmp->type == 'F')
		return (ft_type_f(arg, tmp, buff));
	else
		return ;
}

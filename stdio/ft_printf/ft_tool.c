/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:29:25 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/18 16:32:55 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_null(t_info *tmp, char **str)
{
	if (*str == 0)
	{
		*str = "(null)";
		tmp->type = 's';
		tmp->cast = 0;
	}
}

void	ft_reset_padding(t_padding *padding, char *str)
{
	if (ft_strstr(str, "inf")
	|| ft_strstr(str, "INF")
	|| ft_strstr(str, "nan")
	|| ft_strstr(str, "NAN"))
	{
		padding->zero = 0;
		padding->start = 0;
		padding->stop = 0;
	}
}

char	*ft_sign(t_info *tmp, t_padding *padding, char *str, long double f)
{
	t_sign	sign;
	char	*inf;

	sign = ft_init_sign();
	sign.dd = f;
	if (sign.u < 0)
	{
		padding->prefix = "-";
		f *= -1;
	}
	if (f == (1 / 0.0))
	{
		tmp->zero = 0;
		inf = ft_strdup("inf");
		free(str);
		return (inf);
	}
	if (sign.u == 9221120237041090560)
	{
		tmp->zero = 0;
		inf = ft_strdup("nan");
		free(str);
		return (inf);
	}
	return (str);
}

char	*ft_strtoupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

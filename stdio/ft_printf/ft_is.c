/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:50:19 by mcabrol           #+#    #+#             */
/*   Updated: 2019/06/27 15:42:06 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_type(char c)
{
	if (c == 'c' || c == 'C' ||
		c == 's' || c == 'S' ||
		c == 'd' || c == 'D' ||
		c == 'i' || c == 'o' ||
		c == 'O' || c == 'u' ||
		c == 'U' || c == 'x' ||
		c == 'X' || c == 'f' ||
		c == 'F' || c == 'p' ||
		c == 'i' || c == '%')
		return (1);
	else
		return (0);
}

int		ft_is_flag(char c)
{
	if (c == '#' ||
		c == '0' ||
		c == '-' ||
		c == '+' ||
		c == ' ' ||
		c == '*')
		return (1);
	return (0);
}

int		ft_is_cast(char c)
{
	if (c == 'h' ||
		c == 'l' ||
		c == 'L' ||
		c == 'j' ||
		c == 'z')
		return (1);
	return (0);
}

int		ft_is_colors(char *str)
{
	if (ft_strcmp(str, "eoc") == 0 ||
		ft_strcmp(str, "black") == 0 ||
		ft_strcmp(str, "red") == 0 ||
		ft_strcmp(str, "green") == 0 ||
		ft_strcmp(str, "yellow") == 0 ||
		ft_strcmp(str, "blue") == 0 ||
		ft_strcmp(str, "purple") == 0 ||
		ft_strcmp(str, "cyan") == 0 ||
		ft_strcmp(str, "white") == 0 ||
		ft_strcmp(str, "bg-black") == 0 ||
		ft_strcmp(str, "bg-red") == 0 ||
		ft_strcmp(str, "bg-green") == 0 ||
		ft_strcmp(str, "bg-yellow") == 0 ||
		ft_strcmp(str, "bg-blue") == 0 ||
		ft_strcmp(str, "bg-purple") == 0)
		return (1);
	return (0);
}

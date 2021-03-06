/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:03:00 by mcabrol           #+#    #+#             */
/*   Updated: 2018/10/25 20:25:23 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s != NULL)
	{
		if (*s == '\0')
			return ;
		ft_putchar_fd(*s, fd);
		ft_putstr_fd(++s, fd);
	}
}

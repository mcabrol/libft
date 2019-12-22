/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:21:50 by mcabrol           #+#    #+#             */
/*   Updated: 2018/10/30 12:02:46 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (ft_strlen(s1) > n || ft_strlen(s2) > n)
		return (ft_memcmp(s1, s2, n));
	else
	{
		if (ft_strlen(s1) > ft_strlen(s2))
			return (ft_memcmp(s1, s2, ft_strlen(s1)));
		return (ft_memcmp(s1, s2, ft_strlen(s2)));
	}
}

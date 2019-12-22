/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:43:10 by mcabrol           #+#    #+#             */
/*   Updated: 2018/10/24 16:57:57 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		if (ft_strlen(s1) != ft_strlen(s2))
			return (0);
		if (ft_memcmp(s1, s2, ft_strlen(s1)) == 0)
			return (1);
	}
	return (0);
}

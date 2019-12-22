/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:36:02 by mcabrol           #+#    #+#             */
/*   Updated: 2018/10/18 18:57:19 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) >= ft_strlen(s2))
		return (ft_memcmp(s1, s2, ft_strlen(s1)));
	else
		return (ft_memcmp(s1, s2, ft_strlen(s2)));
}

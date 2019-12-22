/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:59:20 by mcabrol           #+#    #+#             */
/*   Updated: 2018/10/24 15:15:39 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i))
			i++;
		else
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:05:52 by mcabrol           #+#    #+#             */
/*   Updated: 2018/11/05 17:35:02 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = len;
	if (src < dst && src + len > dst)
	{
		while (i > 0)
		{
			*(unsigned char *)(dst + i - 1) = *(unsigned char *)(src + i - 1);
			i--;
		}
	}
	else if (dst + len > src && dst > src)
	{
		i = 0;
		while (i < len)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

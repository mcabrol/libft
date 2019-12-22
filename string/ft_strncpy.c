/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:05:19 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/13 14:21:11 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *end;

	end = ft_memccpy(dst, src, 0, len);
	if (dst + len > end && end != NULL)
		ft_bzero(end, (dst + len) - end);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:20:40 by mcabrol           #+#    #+#             */
/*   Updated: 2018/10/12 14:54:40 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dst;

	dst = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dst == NULL)
		return (0);
	ft_memcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}

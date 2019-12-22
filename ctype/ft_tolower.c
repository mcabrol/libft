/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:39:28 by mcabrol           #+#    #+#             */
/*   Updated: 2018/10/16 14:45:03 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_tolower(int c)
{
	if (ft_isalpha(c) == 1 && c <= 'Z')
		return (c + 32);
	return (c);
}

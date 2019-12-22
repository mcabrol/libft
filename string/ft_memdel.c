/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:00:49 by mcabrol           #+#    #+#             */
/*   Updated: 2018/10/19 14:27:43 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		if (*ap != NULL)
			*ap = NULL;
	}
}

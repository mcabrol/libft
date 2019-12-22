/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:55:21 by mcabrol           #+#    #+#             */
/*   Updated: 2018/10/25 20:28:31 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == ',')
		i++;
	if (s[i] == 0)
		return (ft_strdup(s + i));
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n' || s[j] == ',')
		j--;
	return (str = ft_strsub(s, i, (j - i + 1)));
}

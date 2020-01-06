/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:16:11 by bsuarez-          #+#    #+#             */
/*   Updated: 2019/06/27 18:42:04 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*nt_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str + 1);
	tmp = '\0';
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j--;
		i++;
	}
	return (str);
}

static int		nt_len(unsigned long long nbr, int base)
{
	int		i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	if (i == 0)
		i++;
	return (i);
}

static void		nt_base(unsigned long long nbr, char *str, int base, int i)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr == 0)
		str[i] = '0';
	while (nbr > 0)
	{
		str[i] = hex[(nbr % base)];
		nbr /= base;
		i++;
	}
	nt_strrev(str);
}

char			*ft_itoa_base(unsigned long long nbr, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = ft_strnew(nt_len(nbr, base))))
		return (NULL);
	if (base != 0)
	{
		nt_base(nbr, str, base, i);
		return (str);
	}
	else
		return (0);
}

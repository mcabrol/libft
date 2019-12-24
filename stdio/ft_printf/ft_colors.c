/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 12:23:44 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/18 13:57:39 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_patern(const char *format, int end, int j)
{
	while (format[j])
	{
		if (format[j] == '{')
			break ;
		if (format[j] == '}')
		{
			end = j;
			break ;
		}
		j++;
	}
	return (end);
}

void	ft_colors(const char *format, char *buff, int *i, t_info *tmp)
{
	int		j;
	int		start;
	int		end;
	char	*str;

	j = *i + 1;
	start = *i + 1;
	end = ft_patern(format, 0, j);
	if (end && (str = ft_parse_colors(start, end, format)))
	{
		ft_put_colors(str, buff, tmp, i);
		ft_strdel(&str);
	}
	else
		ft_format('{', buff, tmp);
}

char	*ft_parse_colors(int start, int end, const char *format)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = end - start;
	if ((str = ft_strnew(len + 1)) == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = format[start];
		i++;
		start++;
	}
	if (ft_is_colors(str))
		return (str);
	return (NULL);
}

void	ft_put_colors(char *str, char *buff, t_info *tmp, int *i)
{
	if (ft_strcmp(str, "EOC") == 0)
		ft_strformat(EOC, buff, tmp);
	if (ft_strcmp(str, "red") == 0)
		ft_strformat(RED, buff, tmp);
	if (ft_strcmp(str, "green") == 0)
		ft_strformat(GREEN, buff, tmp);
	if (ft_strcmp(str, "yellow") == 0)
		ft_strformat(YELLOW, buff, tmp);
	if (ft_strcmp(str, "blue") == 0)
		ft_strformat(BLUE, buff, tmp);
	if (ft_strcmp(str, "purple") == 0)
		ft_strformat(PURPLE, buff, tmp);
	if (ft_strcmp(str, "cyan") == 0)
		ft_strformat(CYAN, buff, tmp);
	if (ft_strcmp(str, "white") == 0)
		ft_strformat(WHITE, buff, tmp);
	if (ft_strcmp(str, "bg-black") == 0)
		ft_strformat(BG_BLACK, buff, tmp);
	if (ft_strcmp(str, "bg-red") == 0)
		ft_strformat(BG_RED, buff, tmp);
	if (ft_strcmp(str, "bg-green") == 0)
		ft_strformat(BG_GREEN, buff, tmp);
	if (ft_strcmp(str, "bg-yellow") == 0)
		ft_strformat(BG_YELLOW, buff, tmp);
	*i += (int)ft_strlen(str) + 1;
}

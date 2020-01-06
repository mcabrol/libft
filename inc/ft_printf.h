/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:47:49 by mcabrol           #+#    #+#             */
/*   Updated: 2019/09/18 16:33:40 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "colors.h"

# if defined(__linux__)
    # include <stdint.h>
# endif

# define BUFFSIZE		300

enum				e_cast
{
	NONE,
	H,
	HH,
	L,
	LL,
	D,
	J,
	Z
};

typedef	union		u_sign
{
	double			dd;
	int64_t			u;
}					t_sign;

typedef struct		s_padding
{
	int				start;
	int				stop;
	int				zero;
	char			*prefix;
}					t_padding;

typedef	struct		s_info
{
	int				fd;
	int				res;
	int				buffer;
	int				hash;
	int				plus;
	int				minus;
	int				space;
	int				zero;
	int				precision;
	int				width;
	int				cast;
	int				wild;
	int				dot;
	char			type;
}					t_info;

/*
** ft_printf.c
*/

int					ft_dprintf(int fd, const char *restrict format, ...);
int					ft_printf(const char *restrict format, ...);
void				ft_print(va_list arg, t_info *tmp, char *buff);

/*
** ft_motor.c
*/

int					ft_start(const char *format, va_list arg,
						char *buff, int fd);
int					ft_stop(char c, t_info *tmp, va_list arg, char *buff);

/*
** ft_colors.c
*/

void				ft_colors(const char *format, char *buffer, int *i,
						t_info *tmp);
char				*ft_parse_colors(int start, int end, const char *format);
int					ft_is_colors(char *str);
void				ft_put_colors(char *str, char *buff, t_info *tmp, int *i);

/*
** ft_buffer.c
*/

void				ft_format(char c, char *buff, t_info *tmp);
void				ft_strformat(char *str, char *buff, t_info *tmp);

/*
** ft_char.c
*/

void				ft_type_c(va_list arg, t_info *tmp, char *buff);
t_padding			ft_handle_c(t_info *tmp);
void				ft_print_c(int c, t_info *tmp, char *buff);

/*
** ft_integer.c
*/

void				ft_type_d(va_list arg, t_info *tmp, char *buff);
void				ft_handle_d(t_padding *padding, t_info *tmp,
						intmax_t nbr, char *str);
intmax_t			ft_cast_d(t_info *tmp, va_list arg);
void				ft_print_d(t_padding *padding, char *str,
						char *buff, t_info *tmp);

/*
** ft_octal.c
*/

void				ft_type_o(va_list arg, t_info *tmp, char *buff);
t_padding			ft_handle_o(t_info *tmp, char *str);
uintmax_t			ft_cast_o(t_info *tmp, va_list arg);
void				ft_print_o(t_padding *padding, char *str,
						char *buff, t_info *tmp);

/*
** ft_string.c
*/

void				ft_type_s(va_list arg, t_info *tmp, char *buff);
t_padding			ft_handle_s(t_info *tmp, char *str);
char				*ft_precision_s(t_info *tmp, char *str, int *del);
void				ft_print_s(t_padding *padding, char *str,
						char *buff, t_info *tmp);

/*
** ft_hexa.c
*/

void				ft_type_x(va_list arg, t_info *tmp, char *buff);
t_padding			ft_handle_x(t_info *tmp, char *str, int nbr);
intmax_t			ft_cast_x(t_info *tmp, va_list arg);
void				ft_print_x(t_padding *padding, char *str,
						char *buff, t_info *tmp);

/*
** ft_unsigned.c
*/

void				ft_type_u(va_list arg, t_info *tmp, char *buff);
t_padding			ft_handle_u(t_info *tmp, char *str);
intmax_t			ft_cast_u(t_info *tmp, va_list arg);
void				ft_print_u(t_padding *padding, char *str,
						char *buff, t_info *tmp);

/*
** ft_float.c
*/

void				ft_type_f(va_list arg, t_info *tmp, char *buff);
void				ft_handle_f(t_padding *padding, t_info *tmp,
						long double nbr, char *str);
long double			ft_cast_f(t_info *tmp, va_list arg);
void				ft_print_f(t_padding *padding, char *str,
						char *buff, t_info *tmp);

/*
** ft_is.c
*/

int					ft_is_type(char c);
int					ft_is_flag(char c);
int					ft_is_cast(char c);

/*
** ft_parse.c
*/

void				ft_parse(const char *format, t_info *tmp, int *i);
int					ft_parse_precision(const char *format, int *i);
int					ft_parse_cast(const char *format, int *i, int precast);
void				ft_parse_flag(char flag, t_info *tmp);
void				ft_wildcard(t_info *tmp, va_list arg);

/*
** ft_convert_float.c
*/

char				*ft_float(long double nbr, int precision);

/*
** ft_itoa_b.c
*/

char				*ft_itoa_b(unsigned long long nbr, int base);

/*
** ft_ltoa.c
*/

char				*ft_ltoa(intmax_t n);

/*
** ft_tool.c
*/

char				*ft_sign(t_info *tmp, t_padding *padding, char *str,
					long double f);
char				*ft_strtoupper(char *str);
void				ft_null(t_info *tmp, char **str);
void				ft_reset_padding(t_padding *padding, char *str);
char				*clean_name(char *path);

/*
** ft_debbug.c
*/

void				ft_print_info(t_info *tmp);
void				ft_print_padding(t_padding padding);

/*
** ft_init.c
*/

t_info				ft_init_tmp(int res, int buffsize, int fd);
t_padding			ft_init_padding(void);
t_sign				ft_init_sign(void);
t_info				ft_init_start(int fd);

#endif

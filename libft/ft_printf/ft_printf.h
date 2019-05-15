/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 21:01:20 by julee             #+#    #+#             */
/*   Updated: 2019/03/06 12:06:41 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <locale.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include "../libft.h"

typedef struct		s_1
{
	void			(*pf)(va_list);
	char			*s;
}					t_functions;

typedef struct		s_2
{
	char			flag[6];
	int				width;
	int				precision;
	char			length[3];
	char			conv;
}					t_store;

extern int			g_index;
extern t_store		g_fwpl;

int					ft_printf(const char *format, ...);
void				ft_convert(const char **format, va_list ap);
int					ft_compare(const char *key, const char **format);

void				ft_initializer(void);
void				ft_recog_flag(const char **format);
void				ft_recog_width(const char **format);
void				ft_recog_precision(const char **format);
void				ft_recog_length(const char **format);

void				ft_ptr_conv(va_list ap);
char				*ft_itoa_pointer(size_t n);

void				ft_hexa_conv(va_list ap);

void				ft_unsign_conv(va_list ap);
uintmax_t			ft_cast_unsigned_int(uintmax_t num);
char				*ft_ultimate_itoa_u(uintmax_t num);

void				ft_char_conv(va_list ap);

void				ft_percent_conv(va_list ap);

void				ft_octal_conv(va_list ap);
char				*ft_itoa_octal(uintmax_t n);

void				ft_0n0pre_check(char *str);
int					ft_recog_arg(void);
void				ft_print_pad(char c, int len);
void				ft_putchar_g_i(char c);
void				ft_putstr_g_i(char *str);

char				*ft_ultimate_itoa(intmax_t num);
char				*ft_itoa_hexa(size_t n);

void				ft_int_conv(va_list ap);
void				ft_no_flag(char sign, int width, char *str);
void				ft_flag_zero(char sign, int width, char *str);
void				ft_flag_plus_space(char sign);
intmax_t			ft_cast_int(intmax_t num);

void				ft_str_conv(va_list ap);
void				ft_putstr_ctrl(char *str, int len, int sign);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:18:41 by julee             #+#    #+#             */
/*   Updated: 2019/03/13 10:29:09 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** %->[flag]->[width]->[.precision]->[length]->[conversions]
** [   flag    ] = "#", "0", "-", "+", " "
** [   width   ] = number
** [ .precision] = .number
** [  length   ] = "h", "hh", "l", "ll", "j", "z"
** [conversions] = "sS", "p", "dD", "i", "oO", "uU", "xX", "cC", "%"
*/

int			g_index = 0;
t_functions	g_conv[9] = {
	{.pf = &ft_str_conv, .s = "sS"},
	{.pf = &ft_int_conv, .s = "idD"},
	{.pf = &ft_ptr_conv, .s = "p"},
	{.pf = &ft_hexa_conv, .s = "xX"},
	{.pf = &ft_unsign_conv, .s = "uU"},
	{.pf = &ft_char_conv, .s = "cC"},
	{.pf = &ft_percent_conv, .s = "%"},
	{.pf = &ft_octal_conv, .s = "oO"},
	{0, 0}
};
t_store		g_fwpl;

int		ft_compare(const char *key, const char **format)
{
	if (**format != '\0')
	{
		while (*key)
		{
			if (**format == *key)
			{
				g_fwpl.conv = **format;
				(*format)++;
				return (1);
			}
			key++;
		}
	}
	return (0);
}

void	ft_convert(const char **format, va_list ap)
{
	int i;

	ft_recog_flag(format);
	ft_recog_width(format);
	ft_recog_precision(format);
	ft_recog_length(format);
	i = -1;
	while (++i < 8)
	{
		if (ft_compare(g_conv[i].s, format))
		{
			g_conv[i].pf(ap);
			break ;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		ft_initializer();
		while (*format != '%' && *format)
		{
			write(1, format++, 1);
			g_index++;
		}
		if (*format == '\0')
			return (g_index);
		else if (*format == '%')
			format++;
		if (*format == '\0')
			return (g_index);
		ft_convert(&format, ap);
	}
	va_end(ap);
	return (g_index);
}
/*
**	int		main(void)
**	{
**		wchar_t msg[] = L"안녕하세요, 저는 이준호 입니다.";
**		int		r1;
**		int		r2;
**
**		r1 = ft_printf("%s\n", "42 silicon valley");
**		r2 = printf("%s\n", "42 silicon valley");
**		r1 = ft_printf("%p\n", &r1);
**		r1 = ft_printf("%d\n", 42);
**		r1 = ft_printf("%%\n");
**
**		r1 = ft_printf("%s %p %d %%\n", "ft_pritnf", &r1, 42);
**		r1 = ft_printf("%S\n", msg);
**		printf("return value == %i\n", r1);
**	}
*/

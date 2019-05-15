/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 22:17:28 by julee             #+#    #+#             */
/*   Updated: 2018/09/13 19:52:48 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_cast_int(intmax_t num)
{
	if (g_fwpl.length[0] == 'h' && g_fwpl.length[1] == 'h')
		return ((signed char)num);
	else if (g_fwpl.length[0] == 'h' && g_fwpl.length[1] != 'h')
		return ((short int)num);
	else if (g_fwpl.length[0] == 'l' && g_fwpl.length[1] == 'l')
		return ((long long int)num);
	else if (g_fwpl.length[0] == 'l' && g_fwpl.length[1] != 'l')
		return ((long int)num);
	else if (g_fwpl.length[0] == 'z')
		return ((ssize_t)num);
	else if ((g_fwpl.conv == 'd' || g_fwpl.conv == 'i')
			&& g_fwpl.length[0] == '?')
		return ((int)num);
	return (num);
}

void		ft_flag_plus_space(char sign)
{
	if (g_fwpl.flag[4] == ' ' && g_fwpl.flag[3] == '?')
	{
		(sign == '+') ? ft_putchar_g_i(' ') : ft_putchar_g_i('-');
		g_fwpl.width--;
	}
	else if (g_fwpl.flag[3] == '+')
	{
		(sign == '+') ? ft_putchar_g_i('+') : ft_putchar_g_i('-');
		g_fwpl.width--;
	}
	else if (sign == '-')
	{
		ft_putchar_g_i('-');
		g_fwpl.width--;
	}
}

void		ft_flag_zero(char sign, int width, char *str)
{
	if (g_fwpl.flag[1] == '0' && g_fwpl.flag[2] == '?')
	{
		ft_flag_plus_space(sign);
		if (g_fwpl.precision > 0)
		{
			ft_print_pad(' ', g_fwpl.width - g_fwpl.precision);
			ft_print_pad('0', g_fwpl.precision - width);
		}
		else if (g_fwpl.precision < 0 && g_fwpl.width > width)
			ft_print_pad('0', g_fwpl.width - width);
		ft_putstr_g_i(str);
	}
	else if (g_fwpl.flag[2] == '-')
	{
		ft_flag_plus_space(sign);
		ft_print_pad('0', g_fwpl.precision - width);
		ft_putstr_g_i(str);
		ft_print_pad(' ', g_fwpl.width - width);
	}
}

void		ft_no_flag(char sign, int width, char *str)
{
	if (g_fwpl.flag[1] == '?' && g_fwpl.flag[2] == '?')
	{
		if (sign == '-')
			g_fwpl.width--;
		if (g_fwpl.width > width && g_fwpl.precision < width)
		{
			if (g_fwpl.flag[4] == ' ' || g_fwpl.flag[3] == '+')
				g_fwpl.width--;
			ft_print_pad(' ', g_fwpl.width - width);
		}
		else if (g_fwpl.width > width && g_fwpl.precision > width)
		{
			if (g_fwpl.flag[4] == ' ' || g_fwpl.flag[3] == '+')
				g_fwpl.width--;
			ft_print_pad(' ', g_fwpl.width - g_fwpl.precision);
		}
		ft_flag_plus_space(sign);
		ft_print_pad('0', g_fwpl.precision - width);
		if ((str[0] == '0' && g_fwpl.precision == 0) && g_fwpl.width > 0)
			ft_putchar_g_i(' ');
		else if (!(str[0] == '0' && g_fwpl.precision == 0))
			ft_putstr_g_i(str);
	}
}

void		ft_int_conv(va_list ap)
{
	intmax_t	num;
	char		sign;
	char		*str;
	int			width;

	num = (ft_recog_arg() == 1) ? va_arg(ap, int) : va_arg(ap, intmax_t);
	num = ft_cast_int(num);
	sign = (num < 0) ? '-' : '+';
	str = ft_ultimate_itoa(num);
	width = (int)ft_strlen(str);
	ft_flag_zero(sign, width, str);
	ft_no_flag(sign, width, str);
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 22:24:33 by julee             #+#    #+#             */
/*   Updated: 2018/09/13 19:39:45 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_octal(uintmax_t n)
{
	int		i;
	char	s[50];

	i = 49;
	s[i--] = '\0';
	if (n == 0)
		s[i--] = '0';
	while (n)
	{
		s[i--] = n % 8 + '0';
		n /= 8;
	}
	return (ft_strdup(&s[++i]));
}

void	ft_octal_conv3(char *str, int width)
{
	if (g_fwpl.flag[0] == '?')
	{
		if (g_fwpl.flag[2] == '-')
		{
			ft_print_pad('0', g_fwpl.precision - width);
			ft_putstr_g_i(str);
			ft_print_pad(' ', g_fwpl.width - width);
		}
		else if (g_fwpl.flag[2] == '?')
		{
			if (g_fwpl.flag[1] == '0')
				ft_print_pad('0', g_fwpl.width - width);
			else if (g_fwpl.flag[1] == '?')
				ft_print_pad(' ', g_fwpl.width - width);
			ft_print_pad('0', g_fwpl.precision - width);
			if ((str[0] == '0' && g_fwpl.precision == 0) && g_fwpl.width > 0)
				ft_putchar_g_i(' ');
			else if (str[0] != '0' || g_fwpl.precision != 0)
				ft_putstr_g_i(str);
		}
	}
}

void	ft_octal_conv2(char *str, int width)
{
	if (g_fwpl.flag[2] == '-' && g_fwpl.flag[0] == '#')
	{
		if (str[0] != '0')
			ft_putchar_g_i('0');
		ft_putstr_g_i(str);
		ft_print_pad(' ', g_fwpl.width - width - 1);
	}
	else if (g_fwpl.flag[2] == '?' && g_fwpl.flag[0] == '#')
	{
		if (g_fwpl.flag[1] == '0')
		{
			if (str[0] != '0')
				ft_putchar_g_i('0');
			ft_print_pad('0', g_fwpl.width - width - 1);
			ft_putstr_g_i(str);
		}
		else if (g_fwpl.flag[1] == '?')
		{
			ft_print_pad(' ', g_fwpl.width - width - 1);
			if (str[0] != '0')
				ft_putchar_g_i('0');
			ft_putstr_g_i(str);
		}
	}
}

void	ft_octal_conv(va_list ap)
{
	uintmax_t	num;
	char		*str;
	int			width;

	num = (ft_recog_arg() == 1) ?
		va_arg(ap, unsigned int) : va_arg(ap, uintmax_t);
	num = ft_cast_unsigned_int(num);
	str = ft_itoa_octal(num);
	width = (int)ft_strlen(str);
	ft_octal_conv2(str, width);
	ft_octal_conv3(str, width);
	free(str);
}

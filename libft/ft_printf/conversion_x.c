/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 20:09:31 by julee             #+#    #+#             */
/*   Updated: 2018/09/13 19:39:14 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_0x_flag(char *str)
{
	if (g_fwpl.conv == 'x' && str[0] != '0')
		ft_putstr_g_i("0x");
	else if (g_fwpl.conv == 'X' && str[0] != '0')
		ft_putstr_g_i("0X");
}

void	ft_hexa_conv2(char *str, int width)
{
	if (g_fwpl.flag[0] == '#')
	{
		if (g_fwpl.flag[2] == '-')
		{
			ft_hexa_0x_flag(str);
			ft_putstr_g_i(str);
			ft_print_pad(' ', g_fwpl.width - width - 2);
		}
		else if (g_fwpl.flag[2] == '?')
		{
			if (g_fwpl.flag[1] == '0')
			{
				ft_hexa_0x_flag(str);
				ft_print_pad('0', g_fwpl.width - width - 2);
				ft_putstr_g_i(str);
			}
			else
			{
				ft_print_pad(' ', g_fwpl.width - width - 2);
				ft_hexa_0x_flag(str);
				ft_0n0pre_check(str);
			}
		}
	}
}

void	ft_hexa_conv3(char *str, int width)
{
	if (g_fwpl.flag[0] == '?')
	{
		if (g_fwpl.flag[1] == '0')
		{
			ft_print_pad('0', g_fwpl.width - width);
			ft_putstr_g_i(str);
		}
		else if (g_fwpl.flag[1] == '?')
		{
			if (g_fwpl.flag[2] == '-')
			{
				ft_putstr_g_i(str);
				ft_print_pad(' ', g_fwpl.width - width);
			}
			else if (g_fwpl.flag[2] == '?')
			{
				ft_print_pad(' ', g_fwpl.width - width);
				ft_0n0pre_check(str);
			}
		}
	}
}

void	ft_hexa_conv(va_list ap)
{
	uintmax_t			num;
	char				*str;
	int					width;

	num = (ft_recog_arg() == 1) ?
		va_arg(ap, unsigned int) : va_arg(ap, uintmax_t);
	num = ft_cast_unsigned_int(num);
	str = ft_itoa_hexa(num);
	width = ft_strlen(str);
	ft_hexa_conv2(str, width);
	ft_hexa_conv3(str, width);
	free(str);
}

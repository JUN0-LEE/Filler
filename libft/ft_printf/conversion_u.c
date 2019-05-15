/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 21:54:43 by julee             #+#    #+#             */
/*   Updated: 2018/09/13 19:38:31 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_cast_unsigned_int(uintmax_t num)
{
	if (g_fwpl.length[0] == 'h' && g_fwpl.length[1] == 'h')
		return ((unsigned char)num);
	else if (g_fwpl.length[0] == 'h' && g_fwpl.length[1] != 'h'
			&& g_fwpl.conv != 'U')
		return ((unsigned short int)num);
	else if (g_fwpl.length[0] == 'l' && g_fwpl.length[1] == 'l')
		return ((unsigned long long int)num);
	else if (g_fwpl.length[0] == 'h' && g_fwpl.conv == 'U')
		return ((unsigned long int)num);
	else if (g_fwpl.length[0] == 'l' && g_fwpl.length[1] != 'l')
		return ((unsigned long int)num);
	else if (g_fwpl.length[0] == 'z')
		return ((size_t)num);
	else if ((g_fwpl.conv == 'd' || g_fwpl.conv == 'i')
			&& g_fwpl.length[0] == '?')
		return ((unsigned int)num);
	return (num);
}

char		*ft_ultimate_itoa_u(uintmax_t num)
{
	char	str[50];
	int		i;

	str[49] = '\0';
	i = 48;
	if (num == 0)
		str[i--] = '0';
	while (num)
	{
		str[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (ft_strdup(&str[++i]));
}

void		ft_unsign_conv2(char *str, int width)
{
	if (g_fwpl.flag[1] == '?')
	{
		if (g_fwpl.flag[2] == '-')
		{
			ft_putstr_g_i(str);
			ft_print_pad(' ', g_fwpl.width - width);
		}
		else if (g_fwpl.flag[2] == '?')
		{
			ft_print_pad('0', g_fwpl.precision - width);
			ft_print_pad(' ', g_fwpl.width - width);
			ft_putstr_g_i(str);
		}
	}
}

void		ft_unsign_conv(va_list ap)
{
	uintmax_t	num;
	char		*str;
	int			width;

	num = (ft_recog_arg() == 1) ?
		va_arg(ap, unsigned int) : va_arg(ap, uintmax_t);
	num = ft_cast_unsigned_int(num);
	str = ft_ultimate_itoa_u(num);
	width = (int)ft_strlen(str);
	if (g_fwpl.flag[1] == '0')
	{
		ft_print_pad('0', g_fwpl.width - width);
		ft_putstr_g_i(str);
	}
	ft_unsign_conv2(str, width);
	free(str);
}

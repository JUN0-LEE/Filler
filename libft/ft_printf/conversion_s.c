/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 21:00:45 by julee             #+#    #+#             */
/*   Updated: 2018/09/14 23:19:10 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		byte_calculator(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 64;
		i++;
	}
	return (i);
}

int		byte_header(int byte)
{
	int		res;
	int		header;
	int		i;

	i = 0;
	res = 0;
	header = 128;
	while (i < byte)
	{
		res += header;
		header /= 2;
		i++;
	}
	return (res);
}

void	uni_to_utf(int n)
{
	int				byte;
	unsigned char	*str;
	int				i;

	if (ft_isprint(n))
	{
		ft_putchar(n);
		return ;
	}
	byte = byte_calculator(n);
	str = (unsigned char *)malloc(sizeof(unsigned char) * (byte + 1));
	str[byte] = '\0';
	i = byte - 1;
	while (n)
	{
		str[i--] = n % 64;
		n /= 64;
	}
	i = 1;
	while (i < byte)
		str[i++] += 128;
	str[0] += byte_header(byte);
	write(1, str, byte);
	free(str);
}

void	ft_wcharstr_conv(va_list ap)
{
	wchar_t	*ws;
	int		i;

	ws = va_arg(ap, wchar_t *);
	i = 0;
	while (ws[i])
		uni_to_utf(ws[i++]);
	g_index += i;
}

void	ft_str_conv(va_list ap)
{
	char	*str;
	int		width;

	if (g_fwpl.conv == 'S')
	{
		ft_wcharstr_conv(ap);
		return ;
	}
	if (!(str = va_arg(ap, char *)))
	{
		ft_putstr_g_i("(null)");
		return ;
	}
	width = (int)ft_strlen(str);
	if (g_fwpl.flag[2] != '-' && 0 <= g_fwpl.precision
			&& g_fwpl.precision < width)
		ft_putstr_ctrl(str, g_fwpl.precision, 1);
	else if (g_fwpl.flag[2] != '-' && !(0 <= g_fwpl.precision
				&& g_fwpl.precision < width))
		ft_putstr_ctrl(str, width, 1);
	else if (g_fwpl.flag[2] == '-' && 0 <= g_fwpl.precision
			&& g_fwpl.precision < width)
		ft_putstr_ctrl(str, g_fwpl.precision, -1);
	else
		ft_putstr_ctrl(str, width, -1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globalfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:21:29 by julee             #+#    #+#             */
/*   Updated: 2018/09/14 22:53:16 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_0n0pre_check(char *str)
{
	if ((str[0] == '0' && g_fwpl.precision == 0) && g_fwpl.width > 0)
		ft_putchar_g_i(' ');
	else if (str[0] != '0' || g_fwpl.precision != 0)
		ft_putstr_g_i(str);
}

int		ft_recog_arg(void)
{
	if ((g_fwpl.conv == 'd' || g_fwpl.conv == 'i' || g_fwpl.conv == 'u'
			|| g_fwpl.conv == 'x' || g_fwpl.conv == 'X')
			&& (g_fwpl.length[0] != 'l' && g_fwpl.length[0] != 'z'
				&& g_fwpl.length[0] != 'j'))
		return (1);
	return (0);
}

void	ft_print_pad(char c, int len)
{
	int i;

	i = -1;
	while (++i < len)
		ft_putchar(c);
	g_fwpl.width -= i;
	g_index += i;
}

void	ft_putstr_g_i(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	g_index += i;
}

void	ft_putchar_g_i(char c)
{
	write(1, &c, 1);
	g_index++;
}

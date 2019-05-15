/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pcnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 23:21:01 by julee             #+#    #+#             */
/*   Updated: 2018/09/14 23:21:04 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent_conv(va_list ap)
{
	(void)ap;
	if (g_fwpl.flag[2] == '-')
	{
		ft_putchar_g_i('%');
		ft_print_pad(' ', g_fwpl.width - 1);
	}
	else if (g_fwpl.flag[2] == '?')
	{
		ft_print_pad(' ', g_fwpl.width - 1);
		ft_putchar_g_i('%');
	}
}

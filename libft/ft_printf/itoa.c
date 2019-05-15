/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:47:05 by julee             #+#    #+#             */
/*   Updated: 2018/09/14 22:51:54 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ultimate_itoa(intmax_t num)
{
	char	str[50];
	int		i;

	str[49] = '\0';
	i = 48;
	if (num == 0)
		str[i--] = '0';
	while (num)
	{
		if (num % 10 < 0)
			str[i] = -(num % 10) + '0';
		else
			str[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (ft_strdup(&str[++i]));
}

char	*ft_itoa_hexa(uintmax_t n)
{
	int		i;
	char	s[50];

	i = 49;
	s[i--] = '\0';
	if (n == 0)
		s[i--] = '0';
	while (n)
	{
		if (g_fwpl.conv == 'x')
			s[i--] = (n % 16 > 9) ? n % 16 + 87 : n % 16 + '0';
		else if (g_fwpl.conv == 'X')
			s[i--] = (n % 16 > 9) ? n % 16 + 55 : n % 16 + '0';
		n /= 16;
	}
	return (ft_strdup(&s[++i]));
}

void	ft_putstr_ctrl(char *str, int len, int sign)
{
	int	i;

	if (sign == 1)
	{
		i = -1;
		while (++i < g_fwpl.width - len)
			ft_putchar(' ');
		g_index += i;
	}
	i = -1;
	while (++i < len)
		write(1, &str[i], 1);
	g_index += i;
	if (sign == -1)
	{
		i = -1;
		while (++i < g_fwpl.width - len)
			ft_putchar(' ');
		g_index += i;
	}
}

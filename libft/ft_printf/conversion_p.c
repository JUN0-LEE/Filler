/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 20:14:14 by julee             #+#    #+#             */
/*   Updated: 2018/09/13 19:39:02 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_pointer(size_t n)
{
	int		i;
	char	s[50];

	i = 49;
	s[i--] = '\0';
	if (n == 0)
		s[i--] = '0';
	while (n)
	{
		s[i--] = (n % 16 > 9) ? n % 16 + 87 : n % 16 + '0';
		n /= 16;
	}
	return (ft_strdup(&s[++i]));
}

void	ft_ptr_conv(va_list ap)
{
	size_t		n;
	char		*str;

	n = va_arg(ap, size_t);
	str = ft_itoa_pointer(n);
	ft_putstr_g_i("0x");
	ft_putstr_g_i(str);
	free(str);
}

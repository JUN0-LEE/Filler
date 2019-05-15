/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:01:40 by julee             #+#    #+#             */
/*   Updated: 2019/03/13 17:18:49 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	s;

	if (len == 0)
		return (b);
	str = (unsigned char *)b;
	s = (unsigned char)c;
	i = -1;
	while (++i < len)
		str[i] = s;
	return (b);
}

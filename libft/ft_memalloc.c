/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 21:57:56 by julee             #+#    #+#             */
/*   Updated: 2019/03/13 22:52:01 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *c;

	if (!(c = (void *)malloc(sizeof(void *) * size)))
		return (NULL);
	ft_memset(c, 0, size);
	return (c);
}

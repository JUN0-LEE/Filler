/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:26:19 by julee             #+#    #+#             */
/*   Updated: 2018/09/14 22:53:00 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initializer(void)
{
	int i;

	g_fwpl.flag[5] = '\0';
	i = 0;
	while (i < 5)
		g_fwpl.flag[i++] = '?';
	g_fwpl.width = 0;
	g_fwpl.precision = -1;
	g_fwpl.length[2] = '\0';
	i = 0;
	while (i < 2)
		g_fwpl.length[i++] = '?';
}

void	ft_recog_length(const char **format)
{
	int i;

	i = 0;
	while (**format == 'h' || **format == 'l' || **format == 'j'
			|| **format == 'z')
	{
		if (**format == 'h')
			g_fwpl.length[i++] = 'h';
		else if (**format == 'l')
			g_fwpl.length[i++] = 'l';
		else if (**format == 'j')
			g_fwpl.length[i++] = 'j';
		else if (**format == 'z')
			g_fwpl.length[i++] = 'z';
		(*format)++;
	}
}

void	ft_recog_precision(const char **format)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '-')
			g_fwpl.precision = 0;
		else
			g_fwpl.precision = ft_atoi(*format);
		while (**format == '-' || ('0' <= **format && **format <= '9'))
			(*format)++;
	}
}

void	ft_recog_width(const char **format)
{
	if ('0' <= **format && **format <= '9')
	{
		g_fwpl.width = ft_atoi(*format);
		while ('0' <= **format && **format <= '9')
			(*format)++;
	}
}

void	ft_recog_flag(const char **format)
{
	while (**format == '#' || **format == '0' || **format == '-'
			|| **format == '+' || **format == ' ')
	{
		if (**format == '#')
			g_fwpl.flag[0] = **format;
		else if (**format == '0')
			g_fwpl.flag[1] = **format;
		else if (**format == '-')
			g_fwpl.flag[2] = **format;
		else if (**format == '+')
			g_fwpl.flag[3] = **format;
		else if (**format == ' ')
			g_fwpl.flag[4] = **format;
		(*format)++;
	}
}

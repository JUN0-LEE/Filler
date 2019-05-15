/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:24:54 by julee             #+#    #+#             */
/*   Updated: 2018/08/19 23:03:37 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		buff_check(char *buff, char **line)
{
	char	*c;
	char	*tmp;

	*line = ft_strdup("");
	if (buff[0] != '\0')
	{
		c = ft_strchr(buff, '\n');
		if ((tmp = ft_strchr(++c, '\n')) != NULL)
		{
			c = ft_strsub(buff, c - buff, tmp - c);
			*line = ft_strdup(c);
			free(c);
			ft_strcpy(buff, tmp);
			return (1);
		}
		else
			*line = ft_strdup(c);
	}
	return (0);
}

int		buff_check2(char *buff, char **line)
{
	char	*c;
	char	*tmp;

	if ((c = ft_strchr(buff, '\n')) != NULL)
	{
		c = ft_strsub(buff, 0, c - buff);
		tmp = ft_strjoin(*line, c);
		free(c);
		free(*line);
		*line = tmp;
		return (1);
	}
	else
	{
		tmp = ft_strjoin(*line, buff);
		free(*line);
		*line = tmp;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	int				r;

	if (fd < 0 || line == NULL)
		return (-1);
	if (buff_check(buff, line))
		return (1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (buff_check2(buff, line))
			return (1);
	}
	if (r == 0 && **line != '\0')
	{
		ft_strclr(buff);
		return (1);
	}
	return (r == 0) ? 0 : -1;
}

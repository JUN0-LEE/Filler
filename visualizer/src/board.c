/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:20:06 by julee             #+#    #+#             */
/*   Updated: 2019/04/18 19:20:08 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	board_init(t_mlx *mlx)
{
	int		i;

	if (mlx->board != NULL)
	{
		i = -1;
		while (++i <= mlx->nline)
			free(mlx->board[i]);
		free(mlx->board);
	}
	mlx->board = NULL;
}

void	draw_board(t_mlx *mlx)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			get_board(mlx);
			free(line);
			break ;
		}
		else if (ft_strncmp(line, "==", 2) == 0)
		{
			who_is_winner(line, mlx);
			free(line);
			return ;
		}
		free(line);
	}
	draw_vertical(mlx);
	draw_horizontal(mlx);
	put_color(mlx);
	board_init(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void	get_board(t_mlx *mlx)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	free(line);
	mlx->board = (char **)malloc(sizeof(char *) * (mlx->nline + 1));
	mlx->board[mlx->nline] = 0;
	i = -1;
	while (++i < mlx->nline)
	{
		get_next_line(0, &line);
		mlx->board[i] = ft_strdup(&line[4]);
		free(line);
	}
}

void	get_board_size(char *line, t_mlx *mlx)
{
	while (('a' <= *line && *line <= 'z') || ('A' <= *line && *line <= 'Z'))
		line++;
	mlx->nline = ft_atoi(line++);
	while ('0' <= *line && *line <= '9')
		line++;
	mlx->xcol = ft_atoi(line);
	if (mlx->p == 1)
		mlx->shape = 'O';
	else
		mlx->shape = 'X';
	get_board(mlx);
}

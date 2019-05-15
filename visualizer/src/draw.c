/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:12:43 by julee             #+#    #+#             */
/*   Updated: 2019/04/20 15:54:54 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_dot(t_mlx *mlx, int x, int y, int color)
{
	int		i;

	i = 0;
	mlx->img_addr = mlx_get_data_addr(mlx->img_ptr,
			&(mlx->bpp), &(mlx->size_line), &(mlx->endian));
	mlx->color = mlx_get_color_value(mlx->mlx_ptr, color);
	while (i < mlx->bpp / 8)
	{
		*(mlx->img_addr + (mlx->size_line * y
					+ (mlx->bpp * x) / 8) + i) = mlx->color >> (8 * i) & 0xFF;
		i++;
	}
}

void	draw_vertical(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= mlx->xcol)
	{
		j = -1;
		while (++j <= mlx->nline * 10)
		{
			draw_dot(mlx, 10 + i * 10, 10 + j, 0x000000);
		}
	}
}

void	draw_horizontal(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= mlx->nline)
	{
		j = -1;
		while (++j <= mlx->xcol * 10)
		{
			draw_dot(mlx, 10 + j, 10 + i * 10, 0x000000);
		}
	}
}

void	fill_color(t_mlx *mlx, int y, int x, int color)
{
	int		i;
	int		j;

	x++;
	y++;
	i = x * 10;
	while (++i < x * 10 + 1 + 9)
	{
		j = y * 10;
		while (++j < y * 10 + 1 + 9)
		{
			draw_dot(mlx, i, j, color);
		}
	}
}

void	put_color(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->nline)
	{
		j = -1;
		while (++j < mlx->xcol)
		{
			if (mlx->board[i][j] == 'O')
			{
				(mlx->p1col == 0) ? fill_color(mlx, i, j, 0xE63045)
				: fill_color(mlx, i, j, mlx->p1col);
			}
			else if (mlx->board[i][j] == 'X')
				(mlx->p2col == 0) ? fill_color(mlx, i, j, 0x00FFFF)
				: fill_color(mlx, i, j, mlx->p2col);
			else if (mlx->board[i][j] == 'o' || mlx->board[i][j] == 'x')
				fill_color(mlx, i, j, 0xFFFFFF);
		}
	}
}

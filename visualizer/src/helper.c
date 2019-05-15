/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:22:52 by julee             #+#    #+#             */
/*   Updated: 2019/04/18 19:22:56 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		key_press(int key, void *ptr)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ptr;
	if (key == 53)
		exit(0);
	return (0);
}

int		close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		refresh_window(void *ptr)
{
	t_mlx	*mlx;
	int		h;
	int		w;

	mlx = (t_mlx*)ptr;
	if (mlx->img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	h = (mlx->nline + 2) * 10;
	w = (mlx->xcol + 2) * 10;
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, w, h);
	draw_board(mlx);
	return (0);
}

void	mlx_result(int p1, int p2, t_mlx *mlx)
{
	if (p1 > p2)
	{
		mlx_string_put(mlx->mlx_ptr
		, mlx->win_ptr, 0, 0, 0xFFFFFF, "Player1 (");
		mlx_string_put(mlx->mlx_ptr
		, mlx->win_ptr, 90, 0, 0xFFFFFF, mlx->p1colname);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr
		, 90 + ft_strlen(mlx->p1colname) * 10, 0, 0xFFFFFF, ") Wins!");
	}
	else if (p1 < p2)
	{
		mlx_string_put(mlx->mlx_ptr
		, mlx->win_ptr, 0, 0, 0xFFFFFF, "Player2 (");
		mlx_string_put(mlx->mlx_ptr
		, mlx->win_ptr, 90, 0, 0xFFFFFF, mlx->p2colname);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr
		, 90 + ft_strlen(mlx->p2colname) * 10, 0, 0xFFFFFF, ") Wins!");
	}
	else
		mlx_string_put(mlx->mlx_ptr
		, mlx->win_ptr, 0, 0, 0xFFFFFF, "It's Draw!");
}

void	who_is_winner(char *line, t_mlx *mlx)
{
	int		p1;
	int		p2;
	char	*l;

	while (!('0' <= *line && *line <= '9'))
		line++;
	p1 = ft_atoi(line);
	get_next_line(0, &l);
	while (!('0' <= *l && *l <= '9'))
		l++;
	p2 = ft_atoi(l);
	if (mlx->p1colname == 0)
		mlx->p1colname = "Red";
	if (mlx->p2colname == 0)
		mlx->p2colname = "Blue";
	mlx_result(p1, p2, mlx);
	if (p1 > p2)
		ft_printf("\np1(O) : %d\np2(X) : %d\n== Player 1 Wins! ==\n\n", p1, p2);
	else if (p1 < p2)
		ft_printf("\np1(O) : %d\np2(X) : %d\n== Player 2 Wins! ==\n\n", p1, p2);
	else
		ft_printf("\np1(O) : %d\np2(X) : %d\n== It's Draw! ==\n\n", p1, p2);
	mlx_loop(mlx->mlx_ptr);
}

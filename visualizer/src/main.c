/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:22:25 by julee             #+#    #+#             */
/*   Updated: 2019/04/18 20:43:01 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	set_player_col(char **argv, t_mlx *mlx)
{
	if (ft_strcmp(argv[0], "red") == 0)
		mlx->p1colname = "Red";
	else if (ft_strcmp(argv[0], "green") == 0)
		mlx->p1colname = "Green";
	else if (ft_strcmp(argv[0], "blue") == 0)
		mlx->p1colname = "Blue";
	else if (ft_strcmp(argv[0], "yellow") == 0)
		mlx->p1colname = "Yellow";
	else if (ft_strcmp(argv[0], "purple") == 0)
		mlx->p1colname = "Purple";
	else if (ft_strcmp(argv[0], "grey") == 0)
		mlx->p1colname = "Grey";
	if (ft_strcmp(argv[1], "red") == 0)
		mlx->p2colname = "Red";
	else if (ft_strcmp(argv[1], "green") == 0)
		mlx->p2colname = "Green";
	else if (ft_strcmp(argv[1], "blue") == 0)
		mlx->p2colname = "Blue";
	else if (ft_strcmp(argv[1], "yellow") == 0)
		mlx->p2colname = "Yellow";
	else if (ft_strcmp(argv[1], "purple") == 0)
		mlx->p2colname = "Purple";
	else if (ft_strcmp(argv[1], "grey") == 0)
		mlx->p2colname = "Grey";
}

void	argv_parse(char **argv, t_mlx *mlx)
{
	if (ft_strcmp(argv[0], "red") == 0)
		mlx->p1col = 0xE63045;
	else if (ft_strcmp(argv[0], "green") == 0)
		mlx->p1col = 0x2DD07B;
	else if (ft_strcmp(argv[0], "blue") == 0)
		mlx->p1col = 0x00FFFF;
	else if (ft_strcmp(argv[0], "yellow") == 0)
		mlx->p1col = 0xF0FF00;
	else if (ft_strcmp(argv[0], "purple") == 0)
		mlx->p1col = 0xCD6AE8;
	else if (ft_strcmp(argv[0], "grey") == 0)
		mlx->p1col = 0xCCCCCC;
	if (ft_strcmp(argv[1], "red") == 0)
		mlx->p2col = 0xE63045;
	else if (ft_strcmp(argv[1], "green") == 0)
		mlx->p2col = 0x2DD07B;
	else if (ft_strcmp(argv[1], "blue") == 0)
		mlx->p2col = 0x00FFFF;
	else if (ft_strcmp(argv[1], "yellow") == 0)
		mlx->p2col = 0xF0FF00;
	else if (ft_strcmp(argv[1], "purple") == 0)
		mlx->p2col = 0xCD6AE8;
	else if (ft_strcmp(argv[1], "grey") == 0)
		mlx->p2col = 0xCCCCCC;
	set_player_col(argv, mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	char	*line;

	ft_memset(&mlx, 0, sizeof(t_mlx));
	if (argc == 3)
		argv_parse(&argv[1], &mlx);
	mlx.mlx_ptr = mlx_init();
	while (get_next_line(0, &line) > 0)
		if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			get_board_size(line, &mlx);
			free(line);
			break ;
		}
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr
	, (mlx.xcol + 2) * 10, (mlx.nline + 2) * 10, "NEW WINDOW");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr
	, (mlx.xcol + 2) * 10, (mlx.nline + 2) * 10);
	draw_board(&mlx);
	mlx_hook(mlx.win_ptr, 2, 0, &key_press, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_window, (void *)0);
	mlx_loop_hook(mlx.mlx_ptr, &refresh_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

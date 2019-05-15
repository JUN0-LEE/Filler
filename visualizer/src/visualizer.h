/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:23:35 by julee             #+#    #+#             */
/*   Updated: 2019/04/18 21:40:15 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <math.h>
# include <errno.h>
# define WIDTH 1000
# define HEIGHT 1000

struct				s_board
{
	int				p;
	char			shape;
	int				xcol;
	int				nline;
	char			**board;
};

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_addr;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	color;
	int				p;
	char			shape;
	int				xcol;
	int				nline;
	char			**board;
	int				p1col;
	int				p2col;
	char			*p1colname;
	char			*p2colname;
}					t_mlx;

struct				s_pos
{
	int				x;
	int				y;
};

void				draw_dot(t_mlx *mlx, int x, int y, int color);
void				draw_vertical(t_mlx *mlx);
void				draw_horizontal(t_mlx *mlx);
void				fill_color(t_mlx *mlx, int y, int x, int color);
void				put_color(t_mlx *mlx);

void				board_init(t_mlx *mlx);
void				draw_board(t_mlx *mlx);
void				get_board(t_mlx *mlx);
void				get_board_size(char *line, t_mlx *mlx);

void				who_is_winner(char *line, t_mlx *mlx);
int					key_press(int key, void *ptr);
int					close_window(void *param);
int					refresh_window(void *ptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:21:52 by julee             #+#    #+#             */
/*   Updated: 2019/04/17 16:54:48 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include "../libft/libft.h"
# include <limits.h>

struct				s_pos
{
	int				x;
	int				y;
};

struct				s_board
{
	int				p;
	char			shape;
	int				xcol;
	int				nline;
	char			**board;
	int				**heatmap;
	struct s_list	*list;
	struct s_pos	*min_bpos;
	struct s_pos	*min_ppos;
};

struct				s_piece
{
	int				row;
	int				col;
	char			shape;
	int				piece_size;
	struct s_list	*list;
	char			**piece;
};
/*
** board.c
*/
void				get_player(char *line, struct s_board *board);
int					check_player(char *line, char *pname);
void				get_board(struct s_board *board);
void				get_board_size(char *line, struct s_board *board);
void				get_board_status(struct s_board *board);
/*
** piece.c
*/
void				get_actual_piece(struct s_piece *piece);
void				get_piece_size(char *line, struct s_piece *piece
					, struct s_board *board);
/*
** initializer.c
*/
void				pos_init(int x, int y, struct s_pos *loc);
void				piece_init(struct s_piece *piece);
void				board_init(struct s_board *board);
void				heatmap_alloc(struct s_board *board);
struct s_pos		init_pos(int x, int y);
/*
** main.c
*/
void				get_piece(struct s_piece *piece, struct s_board *board);
void				filler(void);
void				check_min_heatsum(struct s_board *board
					, struct s_piece *piece);
int					get_heatsum(struct s_board *board, struct s_piece *piece
					, struct s_pos *bpos, struct s_pos *ppos);
/*
** heatmap.c
*/
struct s_pos		generate_position(int i, struct s_pos pos);
void				fill_heatmap(struct s_board *board
					, struct s_pos pos, int *count, int heat);
void				draw_heatmap(struct s_board *board, int *count);
void				get_heatmap(struct s_board *board);
int					check_valid_heatsum(int x, int y
					, struct s_board *board, int *count);

#endif

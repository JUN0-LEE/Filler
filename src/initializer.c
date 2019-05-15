/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:23:36 by julee             #+#    #+#             */
/*   Updated: 2019/04/18 21:47:03 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			heatmap_alloc(struct s_board *board)
{
	int		i;
	int		j;

	board->heatmap = (int **)malloc(sizeof(int *) * board->nline);
	i = -1;
	while (++i < board->nline)
		board->heatmap[i] = (int *)malloc(sizeof(int) * board->xcol);
	i = -1;
	while (++i < board->nline)
	{
		j = -1;
		while (++j < board->xcol)
			board->heatmap[i][j] = 0;
	}
}

struct s_pos	init_pos(int x, int y)
{
	struct s_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

void			pos_init(int x, int y, struct s_pos *pos)
{
	pos->x = x;
	pos->y = y;
}

void			board_init(struct s_board *board)
{
	int				p;
	int				i;

	p = board->p;
	if (board->board != NULL)
	{
		i = -1;
		while (++i <= board->nline)
			free(board->board[i]);
		free(board->board);
	}
	if (board->heatmap != NULL)
	{
		i = -1;
		while (++i < board->nline)
			free(board->heatmap[i]);
		free(board->heatmap);
	}
	ft_memset(board, 0, sizeof(struct s_board));
	board->p = p;
}

void			piece_init(struct s_piece *piece)
{
	struct s_list	*list;
	struct s_list	*tmp;
	int				i;

	if (piece->list != NULL)
	{
		list = piece->list;
		while (list)
		{
			tmp = list;
			list = list->next;
			free(tmp);
		}
	}
	if (piece->piece != NULL)
	{
		i = -1;
		while (++i <= piece->row)
			free(piece->piece[i]);
		free(piece->piece);
	}
	ft_memset(piece, 0, sizeof(struct s_piece));
}

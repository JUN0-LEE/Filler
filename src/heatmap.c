/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:39:04 by julee             #+#    #+#             */
/*   Updated: 2019/04/17 16:57:21 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				check_valid_heatsum(int x, int y
				, struct s_board *board, int *count)
{
	if (x < 0 || y < 0 || y >= board->nline
	|| x >= board->xcol || board->heatmap[y][x] == -1)
		return (0);
	else if (board->board[y][x] == board->shape
	|| board->board[y][x] == board->shape + 32)
	{
		(*count)++;
		if (*count > 1)
			return (0);
	}
	return (1);
}

struct s_pos	generate_position(int i, struct s_pos pos)
{
	if (i == 0)
		return (init_pos(pos.x, pos.y + 1));
	else if (i == 2)
		return (init_pos(pos.x + 1, pos.y));
	else if (i == 4)
		return (init_pos(pos.x, pos.y - 1));
	else if (i == 6)
		return (init_pos(pos.x - 1, pos.y));
	return (pos);
}

void			fill_heatmap(struct s_board *board
, struct s_pos pos, int *count, int heat)
{
	struct s_pos	p;
	int				i;

	i = 0;
	while (i < 8)
	{
		p = generate_position(i, pos);
		if ((0 <= p.x && p.x < board->xcol)
		&& (0 <= p.y && p.y < board->nline)
		&& (board->heatmap[p.y][p.x] == 0))
		{
			board->heatmap[p.y][p.x] = heat;
			(*count)--;
		}
		i += 2;
	}
}

void			draw_heatmap(struct s_board *board, int *count)
{
	struct s_pos	pos;
	int				heat;
	int				i;
	int				j;

	heat = 1;
	while (*count)
	{
		i = -1;
		while (++i < board->nline)
		{
			j = -1;
			while (++j < board->xcol)
			{
				if ((heat == 1 && board->heatmap[i][j] == -1)
				|| (heat > 1 && board->heatmap[i][j] == heat - 1))
				{
					pos = init_pos(j, i);
					fill_heatmap(board, pos, count, heat);
				}
			}
		}
		heat++;
	}
}

void			get_heatmap(struct s_board *board)
{
	int		count;
	int		i;
	int		j;

	count = board->nline * board->xcol;
	heatmap_alloc(board);
	i = -1;
	while (++i < board->nline)
	{
		j = -1;
		while (++j < board->xcol)
		{
			if (board->board[i][j] == -(board->shape) + 167
			|| board->board[i][j] == -(board->shape) + 199)
			{
				board->heatmap[i][j] = -1;
				count--;
			}
		}
	}
	draw_heatmap(board, &count);
}

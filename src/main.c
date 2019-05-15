/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:01:25 by julee             #+#    #+#             */
/*   Updated: 2019/04/17 16:55:36 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_heatsum(struct s_board *board, struct s_piece *piece
, struct s_pos *bpos, struct s_pos *ppos)
{
	struct s_pos	p;
	struct s_pos	i;
	int				count;
	int				heatsum;

	count = 0;
	heatsum = 0;
	p.y = bpos->y - ppos->y;
	p.x = bpos->x - ppos->x;
	i.x = -1;
	while (++(i.x) < piece->row)
	{
		i.y = -1;
		while (++(i.y) < piece->col)
			if (piece->piece[i.x][i.y] == '*')
			{
				if (!check_valid_heatsum(i.y + p.x, i.x + p.y, board, &count))
					return (INT_MAX);
				else
					heatsum += board->heatmap[i.x + p.y][i.y + p.x];
			}
	}
	return (heatsum);
}

void	check_min_heatsum(struct s_board *board, struct s_piece *piece)
{
	struct s_list	*plist;
	struct s_list	*blist;
	int				min_hsum;
	int				hsum;

	blist = board->list;
	min_hsum = INT_MAX;
	while (blist)
	{
		plist = piece->list;
		while (plist)
		{
			if ((hsum = get_heatsum(board, piece, blist->content
			, plist->content)) < min_hsum)
			{
				min_hsum = hsum;
				board->min_bpos = blist->content;
				board->min_ppos = plist->content;
			}
			plist = plist->next;
		}
		blist = blist->next;
	}
}

void	get_piece(struct s_piece *piece, struct s_board *board)
{
	char	*line;
	int		i;

	piece->piece = (char **)malloc(sizeof(char *) * (piece->row + 1));
	piece->piece[piece->row] = NULL;
	i = -1;
	while (++i < piece->row)
	{
		get_next_line(0, &line);
		piece->piece[i] = ft_strdup(line);
		free(line);
	}
	get_actual_piece(piece);
	check_min_heatsum(board, piece);
	if (board->min_bpos == 0 || board->min_ppos == 0)
		ft_printf("0 0\n");
	else
		ft_printf("%d %d\n", board->min_bpos->y - board->min_ppos->y
		, board->min_bpos->x - board->min_ppos->x);
	piece_init(piece);
	board_init(board);
}

void	filler(void)
{
	char			*line;
	struct s_board	board;
	struct s_piece	piece;

	ft_memset(&board, 0, sizeof(struct s_board));
	ft_memset(&piece, 0, sizeof(struct s_piece));
	while (get_next_line(0, &line) > 0)
	{
		if (check_player(line, "julee"))
			get_player(line, &board);
		else if (ft_strncmp(line, "Plateau", 7) == 0)
			get_board_size(line, &board);
		else if (ft_strncmp(line, "Piece", 5) == 0)
			get_piece_size(line, &piece, &board);
		free(line);
	}
}

int		main(void)
{
	filler();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:18:00 by julee             #+#    #+#             */
/*   Updated: 2019/04/17 16:55:28 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_actual_piece(struct s_piece *piece)
{
	t_list			*list;
	struct s_pos	loc;
	int				i;
	int				j;

	i = -1;
	while (piece->piece[++i] != NULL)
	{
		j = -1;
		while (piece->piece[i][++j] != '\0')
			if (piece->piece[i][j] == '*')
			{
				pos_init(j, i, &loc);
				if (list == NULL)
				{
					list = ft_lstnew(&loc, sizeof(loc));
					piece->list = list;
				}
				else
				{
					list->next = ft_lstnew(&loc, sizeof(loc));
					list = list->next;
				}
			}
	}
}

void	get_piece_size(char *line, struct s_piece *piece, struct s_board *board)
{
	while (('a' <= *line && *line <= 'z') || ('A' <= *line && *line <= 'Z'))
		line++;
	piece->row = ft_atoi(line++);
	while ('0' <= *line && *line <= '9')
		line++;
	piece->col = ft_atoi(line);
	get_piece(piece, board);
}

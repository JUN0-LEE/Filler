/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:40:28 by julee             #+#    #+#             */
/*   Updated: 2019/04/17 16:55:06 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(char *line, struct s_board *board)
{
	if (line[10] == '1')
		board->p = 1;
	else
		board->p = 2;
}

int		check_player(char *line, char *pname)
{
	int		i;

	i = -1;
	while (line[++i] != '\0')
		if (ft_strncmp(&line[i], pname, 5) == 0)
			return (1);
	return (0);
}

void	get_board_status(struct s_board *board)
{
	t_list			*list;
	struct s_pos	loc;
	struct s_pos	index;

	index.x = -1;
	while (board->board[++index.x] != NULL)
	{
		index.y = -1;
		while (board->board[index.x][++index.y] != '\0')
			if (board->board[index.x][index.y] == board->shape
			|| board->board[index.x][index.y] == board->shape + 32)
			{
				pos_init(index.y, index.x, &loc);
				if (list == NULL)
				{
					list = ft_lstnew(&loc, sizeof(loc));
					board->list = list;
				}
				else
				{
					list->next = ft_lstnew(&loc, sizeof(loc));
					list = list->next;
				}
			}
	}
}

void	get_board(struct s_board *board)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	free(line);
	board->board = (char **)malloc(sizeof(char *) * (board->nline + 1));
	board->board[board->nline] = 0;
	i = -1;
	while (++i < board->nline)
	{
		get_next_line(0, &line);
		board->board[i] = ft_strdup(&line[4]);
		free(line);
	}
	get_board_status(board);
	get_heatmap(board);
}

void	get_board_size(char *line, struct s_board *board)
{
	while (('a' <= *line && *line <= 'z') || ('A' <= *line && *line <= 'Z'))
		line++;
	board->nline = ft_atoi(line++);
	while ('0' <= *line && *line <= '9')
		line++;
	board->xcol = ft_atoi(line);
	if (board->p == 1)
		board->shape = 'O';
	else
		board->shape = 'X';
	get_board(board);
}

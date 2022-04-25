/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:54:41 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/25 11:40:09 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

void	print_piece(t_etris *piece)
{
	printf("(%d, %d)\n", piece->coords[0].x, piece->coords[0].y);
	printf("(%d, %d)\n", piece->coords[1].x, piece->coords[1].y);
	printf("(%d, %d)\n", piece->coords[2].x, piece->coords[2].y);
	printf("(%d, %d)\n\n", piece->coords[3].x, piece->coords[3].y);
}

t_tuple	min_xy(t_etris *piece)
{
	t_tuple	min;
	int		i;

	min.x = 3;
	min.y = 3;
	i = 0;
	while (i < 3)
	{
		if (piece->coords[i].x < min.x)
			min.x = piece->coords[i].x;
		if (piece->coords[i].y < min.y)
			min.y = piece->coords[i].y;
		i++;
	}
	return (min);
}

void	align(t_etris *piece)
{
	t_tuple		min;
	int			i;

	min = min_xy(piece);
	i = 0;
	while (i < 4)
	{
		piece->coords[i].x -= min.x;
		piece->coords[i].y -= min.y;
		i++;
	}
}

t_etris	*new_piece(const char *s, char value)
{
	t_etris		*piece;
	int			i;
	int			block;

	piece = (t_etris *)malloc(sizeof(t_etris));
	piece->value = value;
	piece->next = NULL;
	i = 0;
	block = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (i >= 5)
				piece->coords[block].x = i % 5;
			else
				piece->coords[block].x = i;
			piece->coords[block++].y = i / 5;
		}
		i++;
	}
	align(piece);
	// print_piece(piece);
	return (piece);
}

void	ft_lstaddend(t_etris **alst, t_etris *new)
{
	t_etris	*tmp;

	tmp = *alst;
	if (alst && *alst == NULL)
		*alst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	piecelist_add(t_etris **piecelist, t_etris *piece)
{
	// printf("%p\n", *piecelist);
	if (piecelist && *piecelist == NULL)

		{
			*piecelist = piece;
		}
	else
	{
		while ((*piecelist)->next)
			(*piecelist) = (*piecelist)->next;
		(*piecelist)->next = piece;
	}
}

void	list_test(t_etris **piece)
{
	while ((*piece)->next)
	{
		printf("%c", (*piece)->value);
		printf("(%d, %d) ", (*piece)->coords[0].x, (*piece)->coords[0].y);
		printf("(%d, %d) ", (*piece)->coords[1].x, (*piece)->coords[1].y);
		printf("(%d, %d) ", (*piece)->coords[2].x, (*piece)->coords[2].y);
		printf("(%d, %d)\n", (*piece)->coords[3].x, (*piece)->coords[3].y);
		(*piece) = (*piece)->next;
	}
	printf("%c", (*piece)->value);
	printf("(%d, %d) ", (*piece)->coords[0].x, (*piece)->coords[0].y);
	printf("(%d, %d) ", (*piece)->coords[1].x, (*piece)->coords[1].y);
	printf("(%d, %d) ", (*piece)->coords[2].x, (*piece)->coords[2].y);
	printf("(%d, %d)\n", (*piece)->coords[3].x, (*piece)->coords[3].y);
}

void	revert_coords(t_etris **piece)
{
	char map[4][4];
	while ((*piece)->next)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				map[i][j] = '.';
			}
		}
		for (int k = 0; k < 4; k++)
		{
			map[(*piece)->coords[k].y][(*piece)->coords[k].x] = '#';
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		(*piece) = (*piece)->next;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			map[i][j] = '.';
		}
	}
	for (int k = 0; k < 4; k++)
	{
		map[(*piece)->coords[k].y][(*piece)->coords[k].x] = '#';
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void	parse_pieces()
{
	char	buff[22];
	t_etris	**piece_ptr;
	int		piece_count;
	size_t	size;
	int		ret;
	int		fd;
	char	value;

	piece_ptr = malloc(sizeof(t_etris));

	value = 'A';
	fd = open("./testfiles/valid.txt", 00);
	size = 21;
	while (1)
	{
		ret = read(fd, buff, size);
		if (ret < 20)
			break ;
		buff[ret + 1] = '\0';
		// printf("%s\n", buff);
		if (charcount(buff) && connectioncount(buff))
			ft_lstaddend(piece_ptr, new_piece(buff, value++));
		piece_count++;
	}

	// printf("%c %c %c", (*piece_ptr)->value, (*piece_ptr)->next->value, (*piece_ptr)->next->next->value);
	// list_test(piece_ptr);
	revert_coords(piece_ptr);
}

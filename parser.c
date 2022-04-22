/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:54:41 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/22 11:21:02 by lharkala         ###   ########.fr       */
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
	t_tuple min;
	int i;

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
	t_tuple min;
	int i;

	min = min_xy(piece);
	i = 0;
	while (i < 4)
	{
		piece->coords[i].x -= min.x;
		piece->coords[i].y -= min.y;
		i++;
	}
}
t_etris	*new_piece(const char *s)
{
	t_etris *piece;
	int i;
	int block;

	piece = (t_etris*)malloc(sizeof(t_etris));
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
	print_piece(piece);
	return (piece);
}

void	parse_pieces()
{
	char buff[22];
	int piece_count;
	size_t size;
	int ret;
	int fd;

	fd = open("./testfiles/test.txt", 00);
	size = 21;
	while (1)
	{
		ret = read(fd, buff, size);
		buff[ret] = '\0';
		if (ret < 20)
			break;
		new_piece(buff);
		piece_count++;
	}
}


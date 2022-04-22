/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:54:41 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/22 13:14:10 by lharkala         ###   ########.fr       */
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

t_etris	*new_piece(const char *s)
{
	t_etris		*piece;
	int			i;
	int			block;

	piece = (t_etris *)malloc(sizeof(t_etris));
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

int	connectioncount(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if ((i + 1) < 20 && s[i + 1] == '#')
				count++;
			if ((i - 1) >= 0 && s[i - 1] == '#')
				count++;
			if ((i + 5) < 20 && s[i + 5] == '#')
				count++;
			if ((i - 5) >= 0 && s[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count == 6 || count == 8);
}

int	charcount(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(s[i] == '#' || s[i] == '.'))
				return (invalid_chars);
			if (s[i] == '#' && ++count > 4)
				return (invalid_count);
		}
		else if (s[i] != '\n')
			return (invalid_mapsize);
		i++;
	}
	if (s[20] != '\n')
		return (missing_endl);
	return (correct_count);
}

void	parse_pieces()
{
	char	buff[22];
	int		piece_count;
	size_t	size;
	int		ret;
	int		fd;

	fd = open("./testfiles/test.txt", 00);
	size = 21;
	while (1)
	{
		ret = read(fd, buff, size);
		if (ret < 20)
			break ;
		buff[ret + 1] = '\0';
		printf("%s\n", buff);
		printf("cc: %d\n", charcount(buff));
		printf("connections ok: %d\n", connectioncount(buff));
		new_piece(buff);
		piece_count++;
	}
}

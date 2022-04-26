/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:54:41 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/26 19:33:50 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tuple	min_xy(t_etris *piece)
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

static void	align(t_etris *piece)
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

static t_etris	*new_piece(char *s, char value)
{
	t_etris		*piece;
	int			i;
	int			block;

	if ((charcount(s) < 0 || !connectioncount(s)))
		return (fail);
	piece = (t_etris *)malloc(sizeof(t_etris));
	piece->value = value;
	piece->next = NULL;
	i = 0;
	block = 0;
	while (i < 19)
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
	return (piece);
}

static int	new_list(t_etris **tlist, char *s, int len, char value)
{
	int		i;
	t_etris	*new;
	t_etris	*temp;

	i = 0;
	while (i < len)
	{
		new = new_piece(s + i, value++);
		if (!new)
			return (fail);
		else
		{
			if (i == 0)
			{
				*tlist = new;
				temp = *tlist;
				i += 21;
				continue ;
			}
			temp->next = new;
			temp = temp->next;
		}
		i += 21;
	}
	return (success);
}

int	parse_pieces(char *av)
{
	char	buff[545];
	t_etris	**piece_ptr;
	int		ret;
	int		fd;
	char	value;

	value = 'A';
	piece_ptr = malloc(sizeof(t_etris));
	fd = open(av, 00);
	ret = read(fd, buff, 545);
	if ((ret > 544 || ret < 19) || (ret - 20) % 21 != 0)
		return (fail);
	if (new_list(piece_ptr, buff, ret, value))
		{
			list_test(piece_ptr);
			return (success);
		}
	return (fail);
}

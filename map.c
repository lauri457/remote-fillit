/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:33:16 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/21 14:06:46 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Frees the memory within the map as well as the array.		*/

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		v_del((void **)&(map->array[i]));
		i++;
	}
	v_del((void **)&(map->array));
	v_del((void **)&map);
}

/*	Prints the map.		*/

void print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

/*	Creates a new map and allocates memory to both the map and the	*/
/*	array within it.  fills each initial slot with '.'				*/

t_map *new_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)v_alloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)v_alloc(sizeof(char *) * size);
	i = 0;

	while (i < size)
	{
		map->array[i] = s_new(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

/*	Places tetrimino at a specific location checking if placement	*/
/*	is possible.  Otherwise returns 0.								*/

void	*place_tetrimino(t_etris *tetris, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetris->width)
	{
		j = 0;
		while (j < tetris->height)
		{
			if (tetris->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return(0);
			j++;
		}
		i++;
	}
	set_piece(tetris, map, new_point(x, y), tetris->value);
	return(1);
}

/*	Places a tetrimino piece at the specified location with value character.	*/
/*	Afterwards removes memory stored in point.									*/

void	*set_piece(t_etris *tetris, t_map *map, t_point *point, char value)
{
	int i;
	int j;

	i = 0;
	while (i < tetris->width)
	{
		j = 0;
		while (j < tetris->height)
		{
			if (tetris->pos[j][i] == '#')
				map->array[point->y + j][point->x + i] = value;
			j++;
		}
		i++;
	}
	v_del((void **)&point);
}

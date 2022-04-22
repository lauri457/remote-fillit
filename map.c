/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:33:16 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/22 11:53:40 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Frees the memory within the map as well as the array.		*/

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

/*	Prints the map.		*/

void	print_map(t_map *map)
{
	int	i;

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

t_map	*new_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
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

int	place(t_etris *tetris, t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetris->width)
	{
		j = 0;
		while (j < tetris->height)
		{
			if (tetris->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piece(tetris, map, new_point(x, y), tetris->value);
	return (1);
}

/*	Places a tetrimino piece at the specified location with			*/
/*	value character.  Afterwards removes memory stored in point.	*/

void	set_piece(t_etris *tetris, t_map *map, t_point *point, char value)
{
	int	i;
	int	j;

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
	ft_memdel((void **)&point);
}

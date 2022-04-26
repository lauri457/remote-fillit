/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:33:16 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/26 15:26:24 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Frees the memory within the map as well as the array.		*/

void	free_map(t_map *map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

/*	Prints the map.		*/

void	print_map(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

/*	Creates a new map and allocates memory to both the map and the	*/
/*	array within it.  fills each initial slot with '.'				*/

t_map	*new_map(int map_size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->array = (char **)ft_memalloc(sizeof(char *) * map_size);
	i = 0;
	while (i < map_size)
	{
		map->array[i] = ft_strnew(map_size);
		ft_memset(map->array[i], '.', map_size);
		i++;
	}
	return (map);
}

size_t	count_tetris(t_etris *piecelist)
{
	size_t	count;

	count = 0;
	while (piecelist)
	{
		piecelist = piecelist->next;
		count++;
	}
	return (count);
}

/*	Gets the rounded up square root.		*/

int	round_up_sqrt(int n)
{
	int	map_size;

	map_size = 2;
	while (map_size * map_size < n)
		map_size++;
	return (map_size);
}

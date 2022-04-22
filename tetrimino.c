/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:05:40 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/22 11:11:49 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Frees memory in list structure.		*/

t_list	*free_list(t_list *list)
{
	t_etris	*tetris;
	t_list	*next;

	while (list)
	{
		tetris = (t_etris *)list->content;
		next = list->next;
		free_tetris(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

/*	Frees tetrimino memory.		*/

void	free_tetris(t_etris *tetris)
{
	int	y;

	y = 0;
	while (y < tetris->height)
	{
		ft_memdel((void **)&(tetris->pos[y]));
		y++;
	}
	ft_memdel((void **)&(tetris->pos));
	ft_memdel((void **)&tetris);
}

/*	Creates a new tetrimino structure		*/

t_etris	*new_tetris(char **pos, int width, int height, char value)
{
	t_etris	*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->height = height;
	tetris->width = width;
	tetris->value = value;
	return (tetris);
}

/*	Creates a new point structure		*/

t_point	*new_point(int x, int y)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

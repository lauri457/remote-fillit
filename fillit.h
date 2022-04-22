/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:29:25 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/22 12:17:54 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_tuple
{
	int x;
	int y;
}			t_tuple;

typedef struct s_map
{
	int		size;
	char	**array;
}			t_map;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_etris
{
	char	**pos;
	t_tuple	coords[4];
	int		width;
	int		height;
	char	value;
	struct	s_etris	*next;
}			t_etris;

void	free_map(t_map *map);
void	free_tetris(t_etris *tetris);
void	print_map(t_map *map);
void	set_piece(t_etris *tetris, t_map *map, t_point *point, char value);
void	parse_pieces();

t_list	*free_list(t_list *list);
t_map	*new_map(int size);
t_etris	*new_tetris(char **pos, int width, int height, char value);
t_point	*new_point(int x, int y);

int		place(t_etris *tetris, t_map *map, int x, int y);

#endif
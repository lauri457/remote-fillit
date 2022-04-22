/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:29:25 by oseitama          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/04/22 10:15:47 by lharkala         ###   ########.fr       */
=======
/*   Updated: 2022/04/22 11:11:20 by oseitama         ###   ########.fr       */
>>>>>>> d0748182063369d5e0fdeb5810127277c38b3b7d
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft.h"
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
void	place(t_etris *tetris, t_map *map, int x, int y);
void	set_piece(t_etris *tetris, t_map *map, t_point *point, char value);
t_list	*free_list(t_list *list);
t_map	*new_map(int size);
<<<<<<< HEAD
void	parse_pieces();
=======
t_etris	*new_tetris(char **pos, int width, int height, char value);
t_point	*new_point(int x, int y);
>>>>>>> d0748182063369d5e0fdeb5810127277c38b3b7d

#endif
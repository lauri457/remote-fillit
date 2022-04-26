/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:29:25 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/26 19:41:34 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft/libft.h"
# include <fcntl.h>

// remove
# include <stdlib.h> //?
# include <stdio.h>

enum	e_returns
{
	success = 1,
	fail = 0,
	invalid_count = -1,
	invalid_chars = -2,
	invalid_mapsize = -3,
	missing_endl = -4,
	invalid_end = -5
};

typedef struct s_tuple
{
	int		x;
	int		y;
}			t_tuple;

typedef struct s_map
{
	char	**array;
}			t_map;

typedef struct s_etris
{
	t_tuple			coords[4];
	int				x_offset;
	int				y_offset;
	char			value;
	struct s_etris	*next;
}					t_etris;

void	free_map(t_map *map, int map_size);
void	print_map(t_map *map, int size);
void	place(t_etris *piece, t_map *map, char value);
void	solve(t_etris *piecelist);

t_map	*new_map(int map_size);

int		parse_pieces(char *av);
int		charcount(char *s);
int		connectioncount(char *s);
int		valid(char *s, int size);
int		round_up_sqrt(int n);
int		overlap(t_map *map, t_etris *piece);
int		in_bounds(t_etris *piece, int map_size, char axis);
int		solve_map(t_map	*map, t_etris *piece, int map_size);

size_t	count_tetris(t_etris *piecelist);

//remove
void	list_test(t_etris **piece);
void	print_piece(t_etris *piece);

#endif
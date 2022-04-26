/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:29:25 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/26 15:49:32 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft/libft.h"
# include <fcntl.h>

enum	e_returns
{
	correct_count = 1,
	invalid_count = -1,
	invalid_chars = -2,
	invalid_mapsize = -3,
	missing_endl = -4
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
void	parse_pieces();

t_map	*new_map(int map_size);

int		charcount(char *s);
int		connectioncount(char *s);
int		valid(char *s, int size);
int		round_up_sqrt(int n);
int		overlap(t_map *map, t_etris *piece);
int		in_bounds(t_etris *piece, int map_size, char axis);
int		solve_map(t_map	*map, t_etris *piece, int map_size);

size_t	count_tetris(t_etris *piecelist);

#endif
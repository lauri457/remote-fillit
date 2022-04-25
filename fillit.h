/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:29:25 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/25 11:48:53 by oseitama         ###   ########.fr       */
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
	int x;
	int y;
}			t_tuple;

typedef struct s_map
{
	char	**array;
}			t_map;

typedef struct s_etris
{
	t_tuple	coords[4];
	int		width;
	int		height;
	char	value;
	struct	s_etris	*next;
}			t_etris;

void	free_map(t_map *map, int map_size);
void	print_map(t_map *map, int size);
void	parse_pieces();


t_list	*free_list(t_list *list);
t_map	*new_map(int map_size);

int	charcount(char *s);
int	connectioncount(char *s);
int	valid(char *s, int size);
int	round_up_sqrt(int n);

size_t	count_tetris(t_etris *piecelist);

#endif
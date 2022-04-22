/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:29:25 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/22 10:15:47 by lharkala         ###   ########.fr       */
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
void	print_map(t_map *map);
t_map	*new_map(int size);
void	parse_pieces();

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:17:01 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/26 16:16:54 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_putendl("usage: fillit [input_file]");
	else if (!parse_pieces(av[1]))
		ft_putendl("error");
}

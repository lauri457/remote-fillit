/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:17:01 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/18 16:25:15 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


void print_bits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

unsigned long long check_tetrimino(char *str)
{
	unsigned long long value = 0;
	// unsigned long long test = 0;


	value = 0;
	int i = 0;
	int row = 0;
	while (str[i])
	{
		row = i / 4;
		// printf("\t%d\n", (row * 16));
		if (str[i] == '#')
		{
			// printf("%d\n", i);
			value |= (1L << (63 - (i + (row*11))));
		}
		i++;
	}
	// printf("%llu\n", value);
	print_bits(sizeof(value), &value);
	return (value);
}

void	parse_map()
{
	char buff[22];
	// char *tet;
	size_t size = 21;
	int fd = open("./testfiles/test.txt", O_RDONLY);
	int ret = 0;
	if (ret)
		return ;
	while (1)
	{
		ret = read(fd, buff, size);
		buff[ret] = '\0';
		if (ret < 20)
			break;
		check_tetrimino(buff);
		// tet = check_tetrimino(buff);
		// fd_putstr(tet, STDOUT_FILENO);
		// fd_putstr("   ", STDOUT_FILENO);
		// fd_putnbr(strlen(tet), STDOUT_FILENO);
		// fd_putchar('\n', STDOUT_FILENO);
	}
}

int	main() //(int ac, char **av)
{
	// if (ac == 1)
	// {
		parse_map(); //av[0]);
	// }
}

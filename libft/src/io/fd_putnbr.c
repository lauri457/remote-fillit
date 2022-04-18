/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:17:45 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/12 22:11:22 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	fd_putnbr(int nb, int fd)
{
	int long	lnb;

	lnb = nb;
	if (lnb < 0)
	{
		lnb = -lnb;
		fd_putchar('-', fd);
	}
	if (lnb < 10)
	{
		fd_putchar(lnb + '0', fd);
	}
	else
	{
		fd_putnbr(lnb / 10, fd);
		fd_putnbr(lnb % 10, fd);
	}
}

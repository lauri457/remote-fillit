/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:00:33 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/12 22:11:37 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	declen(int nb)
{
	int		i;

	i = 1;
	if (nb < 0)
		++i;
	while (nb / 10)
	{
		nb /= 10;
		++i;
	}
	return (i);
}

char	*c_itoa(int nb)
{
	int		i;
	char	*res;

	if (nb == -2147483648)
		return (s_dup("-2147483648"));
	i = declen(nb);
	res = s_new(i);
	if (res)
	{
		if (nb < 0)
		{
			res[0] = '-';
			nb *= -1;
		}
		if (nb == 0)
			res[0] = '0';
		while (nb)
		{
			res[--i] = (nb % 10) + '0';
			nb /= 10;
		}
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_nequ.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:01:55 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/04 21:10:59 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	s_nequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		if (s_ncmp(s1, s2, n))
			return (0);
	}
	return (1);
}

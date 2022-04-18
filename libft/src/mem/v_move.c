/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:18:30 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/04 21:26:26 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*v_move(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (src < dest)
		v_cpy(dest, src, n);
	else if (src > dest)
		while (++i < n)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

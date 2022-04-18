/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_set.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:47:51 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/04 21:20:59 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*v_set(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
			*ptr++ = (unsigned char)c;
	return (s);
}

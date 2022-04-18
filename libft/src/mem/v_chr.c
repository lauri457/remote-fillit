/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:45:59 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/07 14:55:45 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*v_chr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if ((*(unsigned char *)s++) == (unsigned char)c)
			return ((void *)s - 1);
	}
	return (NULL);
}

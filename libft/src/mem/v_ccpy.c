/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_ccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:22:30 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/07 14:55:36 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*v_ccpy(void *dest, const void *src, int c, size_t n)
{
	void	*cp;

	cp = v_chr(src, c, n);
	if (cp)
		return (v_cpy(dest, src, (cp - src + 1)) + (cp - src + 1));
	v_cpy (dest, src, n);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:59:11 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/04 21:26:52 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*v_alloc(size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!ptr)
		return (NULL);
	v_set(ptr, 0, size);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:38:04 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/10 20:39:33 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*v_calloc(size_t count, size_t size)
{
	void	*ptr;

	size *= count;
	ptr = (void *)malloc(size);
	if (!ptr)
		return (NULL);
	v_set(ptr, 0, size);
	return (ptr);
}

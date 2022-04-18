/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:16:59 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/04 21:09:42 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	s_lcat(char *dest, const char *src, size_t size)
{
	size_t	len_initial_dest;
	size_t	len_src;
	size_t	i;

	len_initial_dest = s_len(dest);
	len_src = s_len((char *)src);
	i = 0;
	while (src[i] && size && i + len_initial_dest < size - 1)
	{
		dest[i + len_initial_dest] = src[i];
		i++;
	}
	if (!(len_initial_dest > size))
		dest[len_initial_dest + i] = '\0';
	if (size < len_initial_dest)
		return (len_src + size);
	return (len_src + len_initial_dest);
}

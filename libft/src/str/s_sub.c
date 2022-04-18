/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:04:09 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/24 15:00:39 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*s_sub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (s_len(s) < start)
		return (NULL);
	res = s_new(len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
		res[i++] = s[start++];
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:32:43 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/10 21:52:18 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*s_map(char const *s, char (*f)(char))
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	res = s_new(s_len(s));
	if (!res)
		return (NULL);
	i = -1;
	while (s[++i])
		res[i] = f(s[i]);
	return (res);
}

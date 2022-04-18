/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_chr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:10:59 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/04 21:08:34 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*s_chr(const char *s, int c)
{
	--s;
	while (*++s)
		if (*s == (char)(c))
			return ((char *)s);
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

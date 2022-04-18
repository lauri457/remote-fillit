/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:57:16 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/10 13:42:56 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*s_dup(const char *s)
{
	char	*sdup;
	size_t	len;

	len = s_len(s) + 1;
	sdup = (char *) malloc(len * sizeof(char));
	if (!sdup)
		return (NULL);
	return ((char *) v_cpy(sdup, s, len));
}

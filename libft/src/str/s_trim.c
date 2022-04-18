/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:33:00 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/11 15:02:20 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	*s_trim(char const *s)
{
	int		len;
	int		start;
	int		stop;
	char	*result;

	result = NULL;
	if (s)
	{
		len = s_len((char *)s);
		start = 0;
		stop = len - 1;
		while (s[start] && is_whitespace(s[start]))
			++start;
		while (s[stop] && is_whitespace(s[stop]))
			--stop;
		if (start < stop)
			result = s_sub(s, start, len - start - (len - 1 - stop));
		else if (stop == -1)
			result = s_dup("");
	}
	return (result);
}

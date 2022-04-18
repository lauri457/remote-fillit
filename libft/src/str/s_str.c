/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:46:01 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/10 13:50:50 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*s_str(const char *haystack, const char *needle)
{
	int	len_needle;

	if (!*needle)
		return ((char *)haystack);
	len_needle = s_len((char *)needle);
	--haystack;
	while (*++haystack)
	{
		if (!s_ncmp((char *)haystack, (char *)needle, len_needle))
			return ((char *)haystack);
	}
	return (NULL);
}

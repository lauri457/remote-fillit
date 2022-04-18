/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:05:23 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/12 22:10:24 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	wordlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s++ != c)
		++len;
	return (len);
}

char	**s_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**result;

	if (!s)
		return (NULL);
	i = 0;
	words = wordcount(s, c);
	result = (char **)malloc(sizeof(*result) * (words + 1));
	if (!result)
		return (NULL);
	while (words--)
	{
		while (*s && *s == c)
			++s;
		result[i] = s_sub(s, 0, wordlen(s, c));
		if (!result[i++])
			return (result);
		s += wordlen(s, c);
	}
	result[i] = NULL;
	return (result);
}

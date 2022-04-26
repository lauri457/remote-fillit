/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:34:17 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/26 15:43:48 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Checks for invalid characters as well as wrong length of lines.		*/
/*	Also checks for incorrect number of # and missing \n.				*/
/*	Returns error code if any of these are failed.						*/

int	charcount(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(s[i] == '#' || s[i] == '.'))
				return (invalid_chars);
			if (s[i] == '#' && ++count > 4)
				return (invalid_count);
		}
		else if (s[i] != '\n')
			return (invalid_mapsize);
		i++;
	}
	if (s[20] != '\n')
		return (missing_endl);
	return (correct_count);
}

/*	Checks connections.  6 or 8 are valid. others invalid.	*/

int	connectioncount(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if ((i + 1) < 20 && s[i + 1] == '#')
				count++;
			if ((i - 1) >= 0 && s[i - 1] == '#')
				count++;
			if ((i + 5) < 20 && s[i + 5] == '#')
				count++;
			if ((i - 5) >= 0 && s[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count == 6 || count == 8);
}

/*	Loops checking if both charcouint and connection count. 	*/
/*	Returns 1 if it passes. 0 otherwise.						*/

int	valid(char *s, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		if (charcount(s + i) != 4)
			return (0);
		if (connectioncount(s + i) != 6 && connectioncount(s + 1) != 8)
			return (0);
		i++;
	}
	return (1);
}

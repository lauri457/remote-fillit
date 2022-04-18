/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:51:08 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/07 11:15:27 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*join_free(char const *s1, char const *s2)
{
	char	*result;

	result = s_join(s1, s2);
	if (result)
		free((char *)s1);
	return (result);
}

static void	store_mem(char *str, char **rest)
{
	char	*temp;

	if (*str)
	{
		temp = *rest;
		*rest = s_dup(str);
		free(temp);
		temp = NULL;
	}
	else
	{
		v_del((void **)rest);
	}
}

static int	read_mem(char **line, char **rest, char **newline_ptr)
{
	if (*rest && **rest)
	{
		*newline_ptr = s_chr(*rest, '\n');
		if (*newline_ptr)
		{
			**newline_ptr = '\0';
			*line = join_free(*line, *rest);
			store_mem(++(*newline_ptr), rest);
			return (1);
		}
		else
			*line = join_free(*line, *rest);
		if (!s_chr(*rest, '\n'))
			v_del((void *)rest);
	}
	return (0);
}

static int	store_and_join(char *newline_ptr,
					char **rest, char **line, char *buff)
{
	*newline_ptr = '\0';
	store_mem(++newline_ptr, rest);
	*line = join_free(*line, buff);
	return (1);
}

int	fd_getline(const int fd, char **line)
{
	char			*newline_ptr;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static char		*rest[MAX_FD];

	if (fd < 0 || !line || (fd > MAX_FD) || read(fd, 0, 0) == -1)
		return (-1);
	*line = s_new(0);
	if (read_mem(line, &rest[fd], &newline_ptr))
		return (1);
	ret = read(fd, buff, BUFF_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		newline_ptr = s_chr(buff, '\n');
		if (newline_ptr)
			return (store_and_join(newline_ptr, &rest[fd], line, buff));
		*line = join_free(*line, buff);
		ret = read(fd, buff, BUFF_SIZE);
	}
	if (**line && ret == 0)
		return (1);
	free(*line);
	return (ret);
}

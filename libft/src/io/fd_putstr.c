/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:07:39 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/04 21:35:49 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	fd_putstr(char const *s, int fd)
{
	if (!(write(fd, s, s_len(s))))
		return ;
}

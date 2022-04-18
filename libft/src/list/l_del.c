/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:21:45 by lharkala          #+#    #+#             */
/*   Updated: 2022/02/14 15:44:36 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	l_del(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*node;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		node = (*alst)->next;
		l_delone(alst, del);
		*alst = node;
	}
}

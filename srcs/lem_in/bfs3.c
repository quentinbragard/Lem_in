/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:17:46 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/22 13:24:51 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		init_queue(t_room ***queue, int *end)
{
	int i;

	i = 0;
	if (!((*queue) = (t_room **)malloc(sizeof(t_room *) * g_info.nb_rooms * 2)))
		return (0);
	*end = 0;
	(*queue)[*end] = g_info.start;
	while (++i < g_info.nb_rooms * 2)
		(*queue)[i] = NULL;
	return (-1);
}

int		free_queue(t_room ***queue)
{
	free(*queue);
	return (0);
}

int		check_path_validity(t_room **tmp)
{
	t_room *del;

	del = *tmp;
	if ((*tmp) != g_info.end)
		(*tmp)->used = 1;
	(*tmp) = (*tmp)->from;
	del->from = NULL;
	if (*tmp && (*tmp)->used)
		return (-1);
	return (0);
}

int		cycle_detector(void)
{
	t_room	*slow;
	t_room	*fast;

	slow = g_info.end;
	fast = g_info.end;
	while (fast && fast->from)
	{
		slow = slow->from;
		fast = fast->from->from;
		if (fast == slow)
			return (1);
	}
	return (0);
}

int		path_len(t_room *first)
{
	t_room	*tmp;
	int		len;
	int		i;

	len = 2;
	tmp = first;
	while ((i = -1) && tmp != g_info.end)
	{
		len += 1;
		while (++i < tmp->nb_links)
			if (tmp->link[i].stream == 1)
			{
				tmp->link[i].dst->from = tmp;
				tmp = tmp->link[i].dst;
				break ;
			}
	}
	return (len);
}

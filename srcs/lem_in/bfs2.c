/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:17:46 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/22 13:24:00 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		bfs_add_regular(t_room **queue, int i, int j, int *end)
{
	if (queue[i]->link[j].stream != 1 && !queue[i]->link[j].dst->bfs
			&& queue[i]->link[j].dst != g_info.start && queue[i] != g_info.end
			&& (queue[i]->weight < queue[i]->link[j].dst->weight - 1
				|| !queue[i]->link[j].dst->weight))
	{
		queue[i]->link[j].dst->from = queue[i];
		queue[i]->link[j].dst->weight = queue[i]->weight + 1;
		*end += 1;
		queue[*end] = queue[i]->link[j].dst;
		return (1);
	}
	return (0);
}

int		bfs_add_superpos(t_room **queue, int i, int j, int *end)
{
	int		k;
	t_room	*tmp;

	if (!queue[i]->link[j].stream && queue[i]->link[j].dst->bfs
			&& !queue[i]->bfs && queue[i]->link[j].dst != g_info.start
			&& (queue[i]->weight < queue[i]->link[j].dst->weight - 1
				|| !queue[i]->link[j].dst->weight) && queue[i] != g_info.end)
	{
		queue[i]->link[j].dst->from = queue[i];
		queue[i]->link[j].dst->weight = queue[i]->weight + 1;
		tmp = queue[i]->link[j].dst;
		k = 0;
		while (tmp->link[k].stream != -1)
			k++;
		if ((queue[i]->link[j].dst->weight - 1 <= tmp->link[k].dst->weight
			|| !tmp->link[k].dst->weight) && tmp->link[k].dst != g_info.start)
		{
			tmp->link[k].dst->from = tmp;
			tmp->link[k].dst->weight = tmp->weight - 1;
			*end += 1;
			queue[*end] = tmp->link[k].dst;
		}
		return (1);
	}
	return (0);
}

int		bfs_add_upflow(t_room **queue, int i, int j, int *end)
{
	if (queue[i]->link[j].dst->bfs && queue[i] != g_info.end && queue[i]->bfs
	&& queue[i]->link[j].dst != g_info.start && queue[i]->link[j].stream == -1
	&& (queue[i]->weight - 1 <= queue[i]->link[j].dst->weight
		|| !queue[i]->link[j].dst->weight))
	{
		queue[i]->link[j].dst->from = queue[i];
		queue[i]->link[j].dst->weight = queue[i]->weight - 1;
		*end += 1;
		queue[*end] = queue[i]->link[j].dst;
		return (1);
	}
	return (0);
}

int		copy_path(t_path **univ)
{
	t_room	*tmp;
	int		j;
	int		k;
	int		len;

	j = -1;
	k = 0;
	while (++j < g_info.start->nb_links)
		if (g_info.start->link[j].stream)
		{
			len = path_len(g_info.start->link[j].dst);
			(*univ)[k].len = len;
			(*univ)[k].step =
				(t_room **)malloc(sizeof(t_room *) * ((*univ)[k].len));
			tmp = g_info.end;
			while (--len)
			{
				(*univ)[k].step[len] = tmp;
				if (check_path_validity(&tmp))
					return (-1);
			}
			(*univ)[k].step[0] = g_info.start;
			k++;
		}
	return (0);
}

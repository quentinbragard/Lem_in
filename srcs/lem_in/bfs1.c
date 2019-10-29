/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:17:46 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/22 13:21:56 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		bfs(void)
{
	t_room		**queue;
	int			i;
	int			j;
	int			end;

	if ((i = init_queue(&queue, &end)) != -1)
		return (-1);
	while (queue[++i] && end < g_info.nb_rooms * 2 - 1 && (j = -1))
		while (++j < queue[i]->nb_links)
			if (!bfs_add_regular(queue, i, j, &end))
				if (!bfs_add_superpos(queue, i, j, &end))
					bfs_add_upflow(queue, i, j, &end);
	if (!room_exist_in_queue(queue, g_info.end) && !free_queue(&queue))
		return (-1);
	return (free_queue(&queue));
}

int		bfs_normal(void)
{
	t_room		**queue;
	int			i;
	int			j;
	int			end;
	int			success;

	if ((i = init_queue(&queue, &end)) != -1)
		return (-1);
	success = 0;
	while (!success && queue[++i] && (j = -1))
	{
		while (++j < queue[i]->nb_links)
			if (!queue[i]->link[j].dst->bfs && !queue[i]->link[j].dst->weight)
			{
				queue[i]->link[j].dst->from = queue[i];
				queue[i]->link[j].dst->weight = 1;
				queue[++end] = queue[i]->link[j].dst;
				if (queue[end] == g_info.end && (success = 1))
					break ;
			}
	}
	if (!success && !free_queue(&queue))
		return (-1);
	return (free_queue(&queue));
}

int		find_paths(t_path **univ, t_room *map)
{
	int i;

	i = -1;
	if (bfs())
		return (-1);
	if (cycle_detector() && !clear_map(&map))
		if (bfs_normal())
			return (-1);
	mark_bfs_streams();
	if (!clear_map(&map) && copy_path(univ))
		return (-1);
	return (0);
}

t_path	**find_partitions(t_room *map)
{
	t_path	**univ;
	int		n;
	int		i;

	n = -1;
	if (!(g_info.max_path = min_paths()))
		return (NULL);
	if (!(univ = (t_path **)malloc(sizeof(t_path *) * g_info.max_path)))
		return (univ);
	while (++n < g_info.max_path && (i = -1))
	{
		if (!(univ[n] = (t_path *)malloc(sizeof(t_path) * (n + 1))))
			return (univ);
		while (++i < n + 1)
			univ[n][i].step = NULL;
	}
	n = -1;
	while (++n < g_info.max_path)
		if (find_paths(&(univ[n]), map))
			break ;
	g_info.nb_univ = n - 1;
	sort_univ(univ);
	return (univ);
}

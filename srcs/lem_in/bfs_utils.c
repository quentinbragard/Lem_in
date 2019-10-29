/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:25:02 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 13:26:32 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		free_univ(t_path ***univ)
{
	int i;
	int j;

	i = -1;
	while (++i <= g_info.max_path - 1 && (j = -1))
	{
		while (++j <= i)
			free((*univ)[i][j].step);
		free((*univ)[i]);
	}
	free(*univ);
	free(g_info.nb_cycles);
	return (0);
}

void	mark_bfs_streams(void)
{
	t_room	*tmp;
	t_room	*next;
	int		i;

	i = -1;
	while (++i < g_info.end->nb_links)
		if (g_info.end->link[i].dst == g_info.end->from && (next = g_info.end))
			g_info.end->link[i].stream = -1;
	tmp = g_info.end->from;
	while ((i = -1) && tmp != g_info.start)
	{
		tmp->bfs = 1;
		while (++i < tmp->nb_links)
		{
			if (tmp->link[i].dst == tmp->from)
				tmp->link[i].stream = tmp->link[i].stream == 1 ? 0 : -1;
			else if (tmp->link[i].dst == next)
				tmp->link[i].stream = tmp->link[i].stream == -1 ? 0 : 1;
		}
		next = tmp;
		tmp = tmp->from;
	}
	while (++i < tmp->nb_links)
		if (tmp->link[i].dst == next)
			tmp->link[i].stream = 1;
}

int		room_exist_in_queue(t_room **queue, t_room *room)
{
	int	i;

	i = -1;
	while (queue[++i])
		if (queue[i] == room)
			return (i);
	return (0);
}

int		clear_map(t_room **map)
{
	int i;
	int j;
	int count;

	i = -1;
	while (++i < g_info.nb_rooms && (j = -1))
	{
		count = 0;
		(*map)[i].from = NULL;
		(*map)[i].used = 0;
		(*map)[i].weight = 0;
		while (++j < (*map)[i].nb_links)
			if ((*map)[i].link[j].stream)
				count++;
		if (!count)
			(*map)[i].bfs = 0;
	}
	return (0);
}

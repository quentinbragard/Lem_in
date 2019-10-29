/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:39:33 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 13:39:34 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		new_link(t_room room)
{
	int k;

	k = 0;
	while (room.link[k].dst != NULL)
		k++;
	return (k);
}

int		lk_del_ids(char *name[2], t_hash *hash, int i, int j)
{
	if (i == 2)
	{
		free(hash);
		return (0);
	}
	if (i == 1)
	{
		!ft_strcmp(name[i], name[i - 1]) ? g_info.error_type = -4 : 0;
		ft_strdel(&name[1]);
	}
	ft_strdel(&name[0]);
	if (j == 1)
		free(hash);
	return (0);
}

int		init_links(t_room **map)
{
	int i;
	int j;

	i = -1;
	while (++i < g_info.nb_rooms)
	{
		j = -1;
		(*map)[i].link = (t_link *)malloc(sizeof(t_link) * (*map)[i].nb_links);
		while (++j < (*map)[i].nb_links)
		{
			(*map)[i].link[j].dst = NULL;
			(*map)[i].link[j].stream = 0;
		}
	}
	return (0);
}

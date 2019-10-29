/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:32:00 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/08/26 15:38:51 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		min_paths(void)
{
	if (g_info.start->nb_links < g_info.end->nb_links)
	{
		if (!g_info.start->nb_links)
			g_info.error_type = -5;
		return (g_info.start->nb_links);
	}
	else
	{
		if (!g_info.end->nb_links)
			g_info.error_type = -5;
		return (g_info.end->nb_links);
	}
}

int		main(void)
{
	t_room	*map;
	char	*input;
	t_path	**univ;
	int		n;

	input = NULL;
	map = NULL;
	n = -1;
	if (map_init(&map, input) && !free_map(&map))
		return (-1);
	if (!(univ = find_partitions(map)) && !free_map(&map))
		return (ft_usage(g_info.error_type, NULL));
	if (g_info.nb_univ != -1)
	{
		n = best_univ(univ);
		send_ants(univ[n], n);
	}
	free_map(&map);
	free_univ(&univ);
	return (0);
}

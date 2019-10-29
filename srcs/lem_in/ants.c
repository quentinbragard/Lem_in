/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:08:17 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 13:11:31 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*minimize_crossing(int *spread_ants, int *route_len, int nb_routes)
{
	int i;
	int min;
	int max;

	i = -1;
	if (route_len[0])
		min = 0;
	while (check_min_max_duration(spread_ants, nb_routes))
	{
		i = 0;
		max = max_index(spread_ants, nb_routes);
		min = min_index(spread_ants, nb_routes);
		spread_ants[max]--;
		spread_ants[min]++;
		i = -1;
		if (!(spread_ants[max] - route_len[max] + 1))
			nb_routes--;
	}
	return (spread_ants);
}

int		*ants_optimal_repartition(int *route_len, int nb_routes, int nb_ants)
{
	int *spread_ants;
	int i;

	i = -1;
	if (!(spread_ants = (int *)malloc(sizeof(int) * nb_routes)))
		return (NULL);
	while (++i < nb_routes)
		spread_ants[i] = nb_ants / nb_routes + route_len[i] - 1;
	spread_ants[nb_routes - 1] += nb_ants % nb_routes;
	spread_ants = minimize_crossing(spread_ants, route_len, nb_routes);
	i = -1;
	while (++i < nb_routes)
		spread_ants[i] -= (route_len[i] - 1);
	return (spread_ants);
}

void	sort_univ(t_path **univ)
{
	t_path	tmp;
	int		n;
	int		i;
	int		j;

	n = -1;
	if (!n)
		return ;
	while (++n <= g_info.nb_univ && (i = -1))
		while (++i < n)
		{
			j = i - 1;
			while (++j <= n)
				if (univ[n][i].len > univ[n][j].len)
				{
					tmp = univ[n][i];
					univ[n][i] = univ[n][j];
					univ[n][j] = tmp;
				}
		}
}

int		travel_time(t_path *univ, int n)
{
	int i;
	int *ants_repartition;
	int *route_len;

	route_len = malloc(sizeof(int) * (n + 1));
	i = -1;
	while (++i <= n)
		route_len[i] = univ[i].len - 1;
	ants_repartition = ants_optimal_repartition(route_len, n + 1,
			g_info.nb_ants);
	i = -1;
	while (++i <= n)
	{
		univ[i].ants = ants_repartition[i];
	}
	i = 0;
	g_info.nb_cycles[n] = univ[i].ants + univ[i].len - 1;
	while (++i <= n)
		if (univ[i].ants + univ[i].len - 1 > g_info.nb_cycles[n]
				&& univ[i].ants)
			g_info.nb_cycles[n] = univ[i].ants + univ[i].len - 1;
	free(ants_repartition);
	free(route_len);
	return (0);
}

int		best_univ(t_path **univ)
{
	int n;
	int k;
	int min;

	if (!(g_info.nb_cycles = (int *)malloc(sizeof(int) * (g_info.nb_univ + 1))))
		return (-1);
	n = -1;
	while (++n <= g_info.nb_univ)
		travel_time(univ[n], n);
	n = -1;
	min = g_info.nb_cycles[0];
	k = 0;
	while (++n <= g_info.nb_univ)
		if (min > g_info.nb_cycles[n])
		{
			min = g_info.nb_cycles[n];
			k = n;
		}
	return (k);
}

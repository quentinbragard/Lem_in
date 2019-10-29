/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:11:41 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 13:11:56 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		max_index(int *tab, int len)
{
	int r;
	int i;

	r = 0;
	i = -1;
	while (++i < len)
		if (tab[r] <= tab[i])
			r = i;
	return (r);
}

int		min_index(int *tab, int len)
{
	int r;
	int i;

	r = 0;
	i = -1;
	while (++i < len)
		if (tab[r] > tab[i])
			r = i;
	return (r);
}

int		check_min_max_duration(int *step_len, int nb_routes)
{
	int i;

	i = 0;
	while (++i < nb_routes)
		if (step_len[i] != step_len[max_index(step_len, nb_routes)]
				&& step_len[i] != step_len[max_index(step_len, nb_routes)] - 1)
			return (-1);
	return (0);
}

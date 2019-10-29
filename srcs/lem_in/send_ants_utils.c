/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:34:14 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 13:38:54 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		free_ants(t_ants *repartition, int n)
{
	int		i;
	t_ants	*tmp;

	tmp = repartition;
	while (tmp && (i = -1))
	{
		repartition = repartition->next;
		while (++i < n + 1)
			free(tmp->tab[i]);
		free(tmp->tab);
		free(tmp);
		tmp = repartition;
	}
	return (0);
}

int		init_repart_mallocs(t_ants **rep, int ***tab, t_path *univ, int n)
{
	int j;

	j = -1;
	if (!((*rep) = (t_ants *)malloc(sizeof(t_ants))))
		return (-1);
	if (!((*tab) = (int **)malloc(sizeof(int *) * (n + 1))))
		return (-1);
	while (++j < n + 1)
		if (!((*tab)[j] = (int *)malloc(sizeof(int) * univ[j].len)))
			return (-1);
	return (0);
}

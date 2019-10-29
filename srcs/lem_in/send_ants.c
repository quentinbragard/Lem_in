/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:34:14 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 13:38:54 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants	*repartition_init(t_path *univ, int n, int last_ant)
{
	int			**tab;
	int			i;
	int			k;
	int			j;
	t_ants		*repartition;

	i = -1;
	if (!(k = 0) && init_repart_mallocs(&repartition, &tab, univ, n))
		return (NULL);
	while (++i < n + 1 && !(j = 0))
	{
		if (univ[i].ants && ++k)
		{
			tab[i][0] = last_ant + i + 1;
			univ[i].ants = univ[i].ants - 1;
		}
		else
			tab[i][0] = 0;
		while (++j < univ[i].len)
			tab[i][j] = 0;
	}
	repartition->tab = tab;
	repartition->last_ant = last_ant + k;
	repartition->next = NULL;
	return (repartition);
}

void	next_step(t_ants **repartition, t_path *univ, int n)
{
	t_ants		*next_step;
	t_ants		*tmp;
	int			i;
	int			j;

	tmp = *repartition;
	while (tmp->next)
		tmp = tmp->next;
	next_step = repartition_init(univ, n, tmp->last_ant);
	i = -1;
	while (++i < n + 1 && !(j = 0))
		while (++j < univ[i].len)
			(next_step->tab)[i][j] = (tmp->tab)[i][j - 1];
	tmp->next = next_step;
}

char	*create_str_print(char *buf, char *name, int nb)
{
	char *buf_tmp;

	buf = ft_strjoin_left_free(buf, "L");
	buf_tmp = ft_itoa(nb);
	buf = ft_strjoin_left_free(buf, buf_tmp);
	free(buf_tmp);
	buf = ft_strjoin_left_free(buf, "-");
	buf = ft_strjoin_left_free(buf, name);
	buf = ft_strjoin_left_free(buf, " ");
	return (buf);
}

void	print_ants(t_ants *repartition, t_path *univ, int n)
{
	t_ants	*tmp;
	char	*buf;
	int		i;
	int		j;

	tmp = repartition;
	while (tmp)
	{
		buf = ft_strnew(1);
		i = -1;
		while (++i < n + 1 && !(j = 0))
			while (++j < univ[i].len)
				if ((tmp->tab)[i][j])
					buf = create_str_print(buf, univ[i].step[j]->name,
							(tmp->tab)[i][j]);
		tmp = tmp->next;
		if (*buf)
			buf[ft_strlen(buf) - 1] = 0;
		ft_putstr(buf);
		free(buf);
		if (tmp)
			ft_putchar('\n');
	}
}

void	send_ants(t_path *univ, int n)
{
	t_ants	*repartition;
	int		i;

	repartition = repartition_init(univ, n, 0);
	i = -1;
	while (++i < g_info.nb_cycles[n])
		next_step(&repartition, univ, n);
	print_ants(repartition, univ, n);
	free_ants(repartition, n);
}

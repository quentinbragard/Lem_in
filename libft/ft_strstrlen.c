/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 09:09:24 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/05 09:09:37 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstrlen(int nb_str, char **tab)
{
	int i;
	int j;
	int	k;

	k = 0;
	i = 1;
	while (i < nb_str)
	{
		j = 0;
		while (tab[i][j])
		{
			k++;
			j++;
		}
		i++;
	}
	return (k);
}

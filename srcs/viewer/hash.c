/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 12:20:08 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/22 13:28:54 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

unsigned int	hashing_function(char *name)
{
	size_t			i;
	unsigned int	hash;

	i = 0;
	hash = 0;
	while (i != ft_strlen(name))
	{
		hash += name[i++];
		hash += hash << 10;
		hash ^= hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	return (hash % g_info.hash_size);
}

t_hash			*create_hash(void)
{
	unsigned int	i;
	t_hash			*hash;

	i = -1;
	if (!(hash = (t_hash *)malloc(sizeof(t_hash) * (g_info.hash_size))))
	{
		free(hash);
		return (hash);
	}
	while (++i < g_info.hash_size)
	{
		hash[i].index = -1;
		hash[i].name = NULL;
	}
	return (hash);
}

t_hash			*hash_init(t_room *map)
{
	t_hash					*hash;
	unsigned int			i;
	unsigned int			j;

	if (!(hash = create_hash()))
		return (hash);
	i = -1;
	while (++i < (unsigned int)g_info.nb_rooms)
	{
		if (hash[(j = hashing_function(map[i].name))].index == -1)
		{
			hash[j].index = i;
			hash[j].name = map[i].name;
		}
		else
		{
			while (hash[j].index != -1)
				j != g_info.hash_size - 1 ? j++ : (j = 0);
			hash[j].index = i;
			hash[j].name = map[i].name;
		}
	}
	return (hash);
}

int				hash_finder(t_hash *hash, char *name)
{
	unsigned int i;
	unsigned int len;

	len = 0;
	if (hash[(i = hashing_function(name))].name == name)
		return (hash[i].index);
	while (ft_strcmp(hash[i].name, name) && ++len < g_info.hash_size)
	{
		i != g_info.hash_size - 1 ? i++ : (i = 0);
	}
	return (len == g_info.hash_size ? -1 : hash[i].index);
}

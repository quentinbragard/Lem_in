/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:39:33 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 13:47:27 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		links_prework(t_room **map, char *input, t_hash *hash)
{
	char	*id[2];
	int		i;
	int		j;

	while ((i = -1) && *input)
	{
		if (first_line_type(input) == 3)
			input += ft_pos('\n', input);
		else
			while (++i < 2)
			{
				while (*input == ' ')
					input++;
				id[i] = ft_strndup(input, ft_pos(!i ? '-' : '\n', input) - 1);
				if (ft_pos(' ', id[i]))
					id[i][ft_pos(' ', id[i]) - 1] = '\0';
				input += ft_pos(!i ? '-' : '\n', input);
				if ((j = hash_finder(hash, id[i])) == -1
						&& !lk_del_ids(id, hash, i, 1))
					return (-4);
				if (((*map)[j].nb_links += 1) && i)
					lk_del_ids(id, hash, i, 0);
			}
	}
	return (init_links(map));
}

int		double_link(t_room *room1, t_room *room2)
{
	int j;

	j = -1;
	while (++j < (*room1).nb_links)
	{
		if ((*room1).link[j].dst == room2)
		{
			(*room1).nb_links--;
			(*room2).nb_links--;
			return (-1);
		}
	}
	return (0);
}

void	find_room_links(t_room *map, t_hash *hash, char *name[2])
{
	int i;
	int j;
	int k;

	i = -1;
	j = -1;
	i = hash_finder(hash, name[0]);
	j = hash_finder(hash, name[1]);
	if (!double_link(&map[i], &map[j]))
	{
		k = new_link(map[i]);
		map[i].link[k].dst = &map[j];
		k = new_link(map[j]);
		map[j].link[k].dst = &map[i];
	}
}

t_room	*create_links(t_room *map, char *input, t_hash *hash)
{
	char *name[2];

	while (*input || lk_del_ids(name, hash, 2, 0))
	{
		if (first_line_type(input) == 3)
			input += ft_pos('\n', input);
		else
		{
			while (*input && *input == ' ')
				input++;
			name[0] = ft_strndup(input, ft_pos('-', input) - 1);
			if (ft_pos(' ', name[0]))
				name[0][ft_pos(' ', name[0]) - 1] = '\0';
			input += ft_pos('-', input);
			while (*input == ' ')
				input++;
			name[1] = ft_strndup(input, ft_pos('\n', input) - 1);
			if (ft_pos(' ', name[1]))
				name[1][ft_pos(' ', name[1]) - 1] = '\0';
			input += ft_pos('\n', input);
			find_room_links(map, hash, name);
			lk_del_ids(name, hash, 1, 0);
		}
	}
	return (map);
}

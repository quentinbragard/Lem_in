/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:58:27 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 14:00:49 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		first_line_type(char *input)
{
	if (!ft_strncmp(input, "##start", ft_pos('\n', input) - 1))
		return (1);
	else if (!ft_strncmp(input, "##end", ft_pos('\n', input) - 1))
		return (2);
	else if (*input && input[1] && input[2] && *input == '#'
			&& input[1] == '#')
	{
		g_info.error_type = -6;
		return (3);
	}
	else if (*input == '#')
		return (3);
	return (0);
}

int		ft_get_ants_number(char **input)
{
	g_info.nb_rooms = 0;
	while (first_line_type(*input) == 3)
		(*input) += ft_pos('\n', *input);
	g_info.nb_ants = ft_atoi_advanced(input);
	while (**input != '\n' && **input)
		if (*(*input)++ != ' ')
			return (-2);
	if (!**input)
		return (-3);
	*input += 1;
	return (0);
}

t_room	*create_map(char **input)
{
	t_room	*map;
	int		line_type;
	int		i;

	i = 0;
	if (!(map = (t_room *)malloc(sizeof(t_room) * (g_info.nb_rooms))))
		return (map);
	while (i < g_info.nb_rooms)
	{
		if ((line_type = first_line_type(*input)))
		{
			if (line_type == 1)
				g_info.start = &map[i];
			if (line_type == 2)
				g_info.end = &map[i];
		}
		else
		{
			while (**input == ' ')
				(*input)++;
			init_room(&map[i++], input);
		}
		*input += ft_pos('\n', *input);
	}
	return (map);
}

int		hash_error(t_room **map, t_hash **hash)
{
	if (!g_info.start || !g_info.end)
	{
		g_info.error_type = -3;
		return (-1);
	}
	if (!(*hash = hash_init(*map)))
	{
		free(*hash);
		g_info.error_type = -5;
		return (-1);
	}
	return (0);
}

int		map_init(t_room **map, char *input)
{
	char	*tmp;
	t_hash	*hash;
	int		i;

	i = -1;
	hash = NULL;
	if ((g_info.error_type = get_input(&input)))
		return (ft_usage(g_info.error_type, input));
	tmp = input;
	if ((g_info.error_type = ft_get_ants_number(&input)))
		return (ft_usage(g_info.error_type, tmp));
	if ((g_info.error_type = check_rooms(input)))
		return (ft_usage(g_info.error_type, tmp));
	if ((g_info.error_type = check_links(input)))
		return (ft_usage(g_info.error_type, tmp));
	if ((*map = create_map(&input)) && g_info.error_type)
		return (ft_usage(g_info.error_type, tmp));
	if (hash_error(map, &hash))
		return (ft_usage((g_info.error_type = -5), tmp));
	if ((g_info.error_type = links_prework(map, input, hash)))
		return (ft_usage(g_info.error_type, tmp));
	if ((*map = create_links(*map, input, hash)) && min_paths())
		g_info.error_type ? 0 : ft_putstr(tmp);
	free(tmp);
	return (0);
}

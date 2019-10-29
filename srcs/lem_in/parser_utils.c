/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:58:27 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 13:34:57 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		free_map(t_room **map)
{
	int i;

	i = -1;
	if (!*map)
		return (0);
	while (++i < g_info.nb_rooms)
	{
		free((*map)[i].link);
		free((*map)[i].name);
	}
	free(*map);
	return (0);
}

int		get_input(char **input)
{
	char	buf[BUFF_SIZE + 1];
	int		rd;

	*input = ft_strnew(1);
	if (read(0, NULL, 0) == -1)
		return (-1);
	while ((rd = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		*input = ft_strjoin_left_free(*input, buf);
	}
	return (0);
}

void	init_room(t_room *room, char **input)
{
	room->name = ft_strndup(*input, ft_pos(' ', *input) - 1);
	if (room->name[0] == 'L')
		g_info.error_type = -3;
	*input += ft_pos(' ', *input);
	room->co.x = ft_atoi_advanced(input);
	room->co.y = ft_atoi_advanced(input);
	room->bfs = 0;
	room->weight = 0;
	room->from = NULL;
	room->used = 0;
	room->nb_links = 0;
	room->link = NULL;
}

int		ft_usage(int error_type, char *to_free)
{
	if (error_type == -1)
		ft_putendl("ERROR");
	else if (error_type == -2)
		ft_putendl("ERROR");
	else if (error_type == -3)
		ft_putendl("ERROR");
	else if (error_type == -4)
		ft_putendl("ERROR");
	else if (error_type == -5)
		ft_putendl("ERROR");
	else if (error_type == -6)
		ft_putendl("ERROR");
	free(to_free);
	return (1);
}

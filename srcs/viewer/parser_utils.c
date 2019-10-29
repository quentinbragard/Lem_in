/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:58:27 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/25 13:42:06 by qbragard         ###   ########.fr       */
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

int		get_input_viewer(char *input[2])
{
	char	buf[BUFF_SIZE + 1];
	int		rd;

	input[0] = ft_strnew(1);
	if (read(0, NULL, 0) == -1)
		return (-1);
	while ((rd = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		input[0] = ft_strjoin_left_free(input[0], buf);
	}
	input[1] = ft_strdup(ft_strstr(input[0], "\n\n") + 2);
	input[0][ft_strlen(input[0]) - ft_strlen(input[1]) - 1] = 0;
	return (0);
}

void	init_room(t_room *room, char **input)
{
	room->name = ft_strndup(*input, ft_pos(' ', *input) - 1);
	if (room->name[0] == 'L')
		g_info.error_type = -2;
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
	if (error_type)
		write(2, "Error\n", 6);
	free(to_free);
	return (1);
}

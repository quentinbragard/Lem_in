/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:45:09 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/25 14:30:02 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

int	center_coord(t_room *map, t_point co[2])
{
	int i;

	i = -1;
	while (++i < g_info.nb_rooms)
	{
		map[i].co.x -= co[0].x;
		map[i].co.y -= co[0].y;
	}
	co[1].x -= co[0].x;
	co[1].y -= co[0].y;
	co[0].x = 0;
	co[0].y = 0;
	return (0);
}

int	find_min_max_coord(t_room *map, t_point co[2])
{
	int i;

	co[0].x = map[0].co.x;
	co[0].y = map[0].co.y;
	co[1].x = co[0].x;
	co[1].y = co[0].y;
	i = 0;
	while (++i < g_info.nb_rooms)
	{
		if (map[i].co.x < co[0].x)
			co[0].x = map[i].co.x;
		if (map[i].co.y < co[0].y)
			co[0].y = map[i].co.y;
		if (map[i].co.x > co[1].x)
			co[1].x = map[i].co.x;
		if (map[i].co.y > co[1].y)
			co[1].y = map[i].co.y;
	}
	return (1);
}

int	main(void)
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	t_room			*map;
	char			*input[2];
	t_point			co[2];

	ren = NULL;
	map = NULL;
	get_input_viewer(input);
	if (map_init(&map, input[0]) && !free_map(&map))
		return (-1);
	find_min_max_coord(map, co);
	if (!(win = viz_init(&ren)))
		return (-1);
	center_coord(map, co);
	view_lem_in(map, ren, co, input[1]);
	SDL_RenderPresent(ren);
	end_of_viz(ren, win);
	free_map(&map);
	return (0);
}

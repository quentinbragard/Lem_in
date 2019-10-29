/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_operations2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:04:19 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/25 13:48:44 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

SDL_Texture	*first_step(SDL_Renderer *ren, t_room *map,
		t_point co[2], int speed)
{
	SDL_Texture *map_viz;

	map_viz = draw_map_blue(ren, map, co);
	write_room_names(ren, co);
	SDL_RenderPresent(ren);
	SDL_Delay(speed / 4);
	return (map_viz);
}

SDL_Texture	*second_step(SDL_Renderer *ren, t_room *map,
		t_point co[2], char *line)
{
	SDL_Texture *map_viz;

	map_viz = draw_map(ren, map, co);
	write_room_names(ren, co);
	write_all_numbers(ren, map, co, line);
	SDL_RenderPresent(ren);
	return (map_viz);
}

SDL_Texture	*last_step(SDL_Renderer *ren, t_room *map,
		t_point co[2], t_hash *hash)
{
	SDL_Texture *map_viz;

	actualize_flux(map, NULL, hash);
	map_viz = draw_map(ren, map, co);
	return (map_viz);
}

t_hash		*view_init(char **line, int *running, int *speed, t_room *map)
{
	t_hash	*hash;

	hash = hash_init(map);
	*line = NULL;
	*running = 1;
	*speed = SPEED;
	return (hash);
}

int			pause_check(int running)
{
	while (running == 2)
	{
		wait_for_space(&running);
		if (!running)
			return (0);
	}
	return (1);
}

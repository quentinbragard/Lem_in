/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:55:41 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/25 13:56:38 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

int	view_lem_in(t_room *map, SDL_Renderer *ren, t_point co[2], char *input)
{
	t_hash		*hash;
	char		*line;
	SDL_Texture	*map_viz;
	int			running;
	int			speed;

	hash = view_init(&line, &running, &speed, map);
	while ((running = check_event(running, &speed))
			&& (line = get_next_line_string(&input, line)))
	{
		if (!pause_check(running))
			return (0);
		actualize_flux(map, line, hash);
		map_viz = first_step(ren, map, co, speed);
		SDL_DestroyTexture(map_viz);
		map_viz = second_step(ren, map, co, line);
		SDL_Delay(speed);
		SDL_DestroyTexture(map_viz);
	}
	actualize_flux(map, NULL, hash);
	map_viz = last_step(ren, map, co, hash);
	wait_for_closing(ren, map_viz, running, speed);
	return (0);
}

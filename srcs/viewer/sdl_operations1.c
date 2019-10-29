/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_operations1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:15:35 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/25 13:48:00 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

void		create_rect(int i, t_room *map, SDL_Rect *point, t_point co[2])
{
	point[i].x = (WIDTH - 50) * map[i].co.x / co[1].x;
	point[i].y = (HEIGHT - 50) * map[i].co.y / co[1].y;
	point[i].w = 50;
	point[i].h = 50;
}

void		draw_rect(SDL_Renderer *ren, SDL_Rect point, int i, t_room *map)
{
	if (map[i].used && &map[i] != g_info.end)
		SDL_SetRenderDrawColor(ren, 255, 10, 0, 100);
	else
		SDL_SetRenderDrawColor(ren, 0, 10, 255, 100);
	SDL_RenderFillRect(ren, &point);
	SDL_RenderDrawRect(ren, &point);
}

void		draw_rect_blue(SDL_Renderer *ren, SDL_Rect point)
{
	SDL_SetRenderDrawColor(ren, 0, 10, 255, 100);
	SDL_RenderFillRect(ren, &point);
	SDL_RenderDrawRect(ren, &point);
}

SDL_Texture	*draw_map(SDL_Renderer *ren, t_room *map, t_point co[2])
{
	SDL_Texture	*map_viz;
	SDL_Rect	point[g_info.nb_rooms];
	SDL_Rect	position;
	int			i;

	if (!(map_viz = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888,
					SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)))
		return (sdl_errors("texture map initialisation"));
	position.x = WIDTH * 0.1;
	position.y = HEIGHT * 0.1;
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 0);
	SDL_SetRenderTarget(ren, map_viz);
	i = -1;
	while (++i < g_info.nb_rooms)
	{
		draw_links_i(i, ren, map, co);
		create_rect(i, map, point, co);
		draw_rect(ren, point[i], i, map);
	}
	SDL_SetRenderTarget(ren, NULL);
	SDL_QueryTexture(map_viz, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(ren, map_viz, NULL, &position);
	return (map_viz);
}

SDL_Texture	*draw_map_blue(SDL_Renderer *ren, t_room *map, t_point co[2])
{
	SDL_Texture	*map_viz;
	SDL_Rect	point[g_info.nb_rooms];
	SDL_Rect	position;
	int			i;

	if (!(map_viz = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888,
					SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)))
		return (sdl_errors("texture map initialisation"));
	position.x = WIDTH * 0.1;
	position.y = HEIGHT * 0.1;
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 0);
	SDL_SetRenderTarget(ren, map_viz);
	i = -1;
	while (++i < g_info.nb_rooms)
	{
		draw_links_i(i, ren, map, co);
		create_rect(i, map, point, co);
		draw_rect_blue(ren, point[i]);
	}
	SDL_SetRenderTarget(ren, NULL);
	SDL_QueryTexture(map_viz, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(ren, map_viz, NULL, &position);
	return (map_viz);
}

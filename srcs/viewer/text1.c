/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:17:39 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/25 13:54:55 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

void			end_of_police(SDL_Renderer *ren, TTF_Font *police,
		SDL_Surface *text)
{
	SDL_FreeSurface(text);
	TTF_CloseFont(police);
	SDL_SetRenderTarget(ren, NULL);
}

void			set_color_names(SDL_Color *color)
{
	color->r = 255;
	color->g = 0;
	color->b = 0;
	color->a = 100;
}

SDL_Texture		*write_end_name(SDL_Renderer *ren, t_point co[2])
{
	SDL_Surface	*text;
	SDL_Texture	*name;
	TTF_Font	*police;
	SDL_Rect	position;
	SDL_Color	color;

	text = NULL;
	name = NULL;
	SDL_SetRenderTarget(ren, name);
	SDL_SetSurfaceBlendMode(text, SDL_BLENDMODE_BLEND);
	police = TTF_OpenFont("./fonts/deadpack.ttf", 16);
	set_color_names(&color);
	position.x = ((WIDTH - 50) * g_info.end->co.x / co[1].x)
		+ (WIDTH * 0.1 + 5);
	position.y = ((HEIGHT - 50) * g_info.end->co.y / co[1].y)
		+ (HEIGHT * 0.1 + 55);
	text = TTF_RenderText_Blended(police, "END", color);
	name = SDL_CreateTextureFromSurface(ren, text);
	end_of_police(ren, police, text);
	SDL_QueryTexture(name, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(ren, name, NULL, &position);
	return (name);
}

SDL_Texture		*write_start_name(SDL_Renderer *ren, t_point co[2])
{
	SDL_Surface	*text;
	SDL_Texture	*name;
	TTF_Font	*police;
	SDL_Rect	position;
	SDL_Color	color;

	text = NULL;
	name = NULL;
	SDL_SetRenderTarget(ren, name);
	SDL_SetSurfaceBlendMode(text, SDL_BLENDMODE_BLEND);
	police = TTF_OpenFont("fonts/deadpack.ttf", 16);
	set_color_names(&color);
	position.x = ((WIDTH - 50) * g_info.start->co.x / co[1].x)
		+ (WIDTH * 0.1);
	position.y = ((HEIGHT - 50) * g_info.start->co.y / co[1].y)
		+ (HEIGHT * 0.1 + 55);
	text = TTF_RenderText_Blended(police, "START", color);
	name = SDL_CreateTextureFromSurface(ren, text);
	end_of_police(ren, police, text);
	SDL_QueryTexture(name, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(ren, name, NULL, &position);
	return (name);
}

void			write_room_names(SDL_Renderer *ren, t_point co[2])
{
	write_start_name(ren, co);
	write_end_name(ren, co);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:15:07 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/25 13:44:18 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

void		*sdl_errors(char const *message)
{
	ft_putstr_fd("Error ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(SDL_GetError(), 2);
	ft_putstr_fd(".\n", 2);
	SDL_Quit();
	return (NULL);
}

int			end_of_viz(SDL_Renderer *ren, SDL_Window *win)
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	TTF_Quit();
	return (0);
}

SDL_Window	*viz_init(SDL_Renderer **ren)
{
	SDL_Window *win;

	win = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING))
		return (sdl_errors("SDL_Init"));
	if (TTF_Init())
		return (sdl_errors("TTF_init"));
	if (!(win = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					WIDTH * 1.2, HEIGHT * 1.2, SDL_WINDOW_SHOWN)))
		return (sdl_errors("window initialisation"));
	if (!(*ren = SDL_CreateRenderer(win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		SDL_DestroyWindow(win);
		return (sdl_errors("renderer initialisation"));
	}
	return (win);
}

int			check_event(int running, int *speed)
{
	SDL_Event event;

	if (!running)
		return (0);
	while (SDL_PollEvent(&event))
	{
		if ((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type
					&& SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
			return (0);
		if ((SDL_KEYDOWN == event.type && SDL_SCANCODE_SPACE
					== event.key.keysym.scancode))
			return (2);
		if ((SDL_KEYDOWN == event.type && SDL_SCANCODE_RIGHT
					== event.key.keysym.scancode))
			*speed = *speed > 50 ? *speed - 50 : 10;
		if ((SDL_KEYDOWN == event.type && SDL_SCANCODE_LEFT
					== event.key.keysym.scancode))
			*speed += 50;
	}
	return (1);
}

void		wait_for_space(int *running)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if ((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type
					&& SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
		{
			*running = 0;
			return ;
		}
		if ((SDL_KEYDOWN == event.type && SDL_SCANCODE_SPACE
					== event.key.keysym.scancode))
			*running = 1;
	}
}

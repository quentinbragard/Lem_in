/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:51:13 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/25 14:29:50 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

SDL_Texture	*write_ant_number(SDL_Renderer *ren, t_room room,
		t_point co[2], char *ant_num)
{
	SDL_Surface	*text;
	SDL_Texture	*num;
	TTF_Font	*police;
	SDL_Rect	position;
	SDL_Color	color;

	text = NULL;
	num = NULL;
	SDL_SetRenderTarget(ren, num);
	SDL_SetSurfaceBlendMode(text, SDL_BLENDMODE_BLEND);
	police = TTF_OpenFont("./fonts/arial_bold.ttf", 20);
	color.r = 0;
	color.g = 10;
	color.b = 255;
	color.a = 100;
	position.x = ((WIDTH - 50) * room.co.x / co[1].x) + (WIDTH * 0.1 + 5);
	position.y = ((HEIGHT - 50) * room.co.y / co[1].y) + (HEIGHT * 0.1 + 10);
	text = TTF_RenderText_Blended(police, ant_num, color);
	num = SDL_CreateTextureFromSurface(ren, text);
	SDL_FreeSurface(text);
	TTF_CloseFont(police);
	SDL_SetRenderTarget(ren, NULL);
	SDL_QueryTexture(num, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(ren, num, NULL, &position);
	return (num);
}

int			space_counter(char *line)
{
	int count;

	count = 0;
	while (*line)
		if (*line++ == ' ')
			count++;
	return (count);
}

char		**ant_in_room(char **line)
{
	char	**ret;
	char	*tmp;
	int		count;
	int		k;

	if (!(ret = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	ret[0] = room_name(line);
	count = 0;
	k = 0;
	tmp = *line;
	while (*(++*line) != ' ')
		count++;
	*line = tmp;
	if (!(ret[1] = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	while (*(++*line) != ' ')
		ret[1][k++] = **line;
	ret[1][k] = '\0';
	return (ret);
}

int			find_room(char *name, t_room *map)
{
	int i;

	i = -1;
	while (++i < g_info.nb_rooms)
		if (!ft_strcmp(map[i].name, name))
			return (i);
	return (-1);
}

void		write_all_numbers(SDL_Renderer *ren, t_room *map,
		t_point co[2], char *line)
{
	int		i;
	char	**ant_num;
	int		spaces;

	i = -1;
	spaces = space_counter(line);
	while (++i < spaces + 1)
	{
		ant_num = ant_in_room(&line);
		write_ant_number(ren, map[find_room(ant_num[1], map)], co, ant_num[0]);
	}
}

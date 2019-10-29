/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:07:24 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/25 14:00:40 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

char		*get_next_line_string(char **input, char *line)
{
	int i;

	i = 0;
	ft_strdel(&line);
	if (!(line = (char *)malloc(sizeof(char) * ft_pos('\n', *input) + 1)))
		return (NULL);
	while ((*input)[i] && (*input)[i] != '\n')
	{
		line[i] = (*input)[i];
		i++;
	}
	line[i] = 0;
	if (!*line)
		return (NULL);
	*input = ((*input) + i + 1);
	return (line);
}

int			get_room_names(char *line, char ***names)
{
	char	**tmp;
	int		i;
	int		len;

	tmp = ft_strsplit(line, ' ');
	(*names) = NULL;
	len = 0;
	while (tmp[len])
		len++;
	(*names) = (char **)malloc(sizeof(char *) * (len + 1));
	i = -1;
	while (tmp[++i])
		(*names)[i] = ft_strdup(tmp[i] + ft_pos('-', tmp[i]));
	i = -1;
	while (++i < len)
		ft_strdel(&tmp[i]);
	free(tmp);
	return (len);
}

int			actualize_flux(t_room *map, char *line, t_hash *hash)
{
	char	**names;
	int		i;
	int		len;

	map = (t_room *)map;
	i = -1;
	len = 0;
	while (++i < g_info.nb_rooms)
		map[i].used = 0;
	names = NULL;
	i = -1;
	if (line)
		len = get_room_names(line, &names);
	while (++i < len)
	{
		map[hash_finder(hash, names[i])].used = 1;
	}
	return (0);
}

void		draw_links_i(int i, SDL_Renderer *ren, t_room *map, t_point co[2])
{
	int	j;

	SDL_SetRenderDrawColor(ren, 0, 10, 255, 100);
	j = -1;
	while (++j < map[i].nb_links)
	{
		SDL_RenderDrawLine(ren, (WIDTH - 50) * map[i].co.x / co[1].x,
				(HEIGHT - 50) * map[i].co.y / co[1].y, (WIDTH - 50) *
				map[i].link[j].dst->co.x / co[1].x, (HEIGHT - 50) *
				map[i].link[j].dst->co.y / co[1].y);
	}
}

void		wait_for_closing(SDL_Renderer *ren, SDL_Texture *map_viz,
		int running, int speed)
{
	if (running)
	{
		while ((running = check_event(running, &speed)))
			SDL_RenderPresent(ren);
		SDL_DestroyTexture(map_viz);
	}
}

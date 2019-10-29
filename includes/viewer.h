/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:44:00 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/25 14:34:01 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_H
# define VIEWER_H
# define HEIGHT 1000
# define WIDTH 1200
# define SPEED 500
# include <SDL2/SDL.h>
# include <SDL_ttf.h>
# include "lem_in.h"

typedef struct		s_send
{
	char			*room;
	int				ant;
	struct s_send	*next;
}					t_send;

int					get_input_viewer(char *input[2]);
char				*get_next_line_string(char **input, char *line);
int					actualize_flux(t_room *map, char *line, t_hash *hash);
int					view_lem_in(t_room *map, SDL_Renderer *ren,
		t_point co[2], char *input);
void				*sdl_errors(char const *message);
int					center_coord(t_room *map, t_point co[2]);
int					check_event(int running, int *speed);
void				write_room_names(SDL_Renderer *ren, t_point co[2]);
void				write_all_numbers(SDL_Renderer *ren, t_room *map,
		t_point co[2], char *line);
void				wait_for_space(int *running);
SDL_Texture			*draw_map(SDL_Renderer *ren, t_room *map, t_point co[2]);
SDL_Texture			*draw_map_blue(SDL_Renderer *ren, t_room *map,
		t_point co[2]);
SDL_Window			*viz_init(SDL_Renderer **ren);
int					end_of_viz(SDL_Renderer *ren, SDL_Window *win);
void				draw_links_i(int i, SDL_Renderer *ren, t_room *map,
		t_point co[2]);
SDL_Texture			*first_step(SDL_Renderer *ren, t_room *map,
		t_point co[2], int speed);
SDL_Texture			*second_step(SDL_Renderer *ren, t_room *map,
		t_point co[2], char *line);
SDL_Texture			*last_step(SDL_Renderer *ren, t_room *map,
		t_point co[2], t_hash *hash);
t_hash				*view_init(char **line, int *running, int *speed,
		t_room *map);
int					pause_check(int running);
void				wait_for_closing(SDL_Renderer *ren, SDL_Texture *map_viz,
		int running, int speed);
void				draw_links_i(int i, SDL_Renderer *ren, t_room *map,
		t_point co[2]);
int					actualize_flux(t_room *map, char *line, t_hash *hash);
int					get_room_names(char *line, char ***names);
char				*get_next_line_string(char **input, char *line);
char				*room_name(char **line);

#endif

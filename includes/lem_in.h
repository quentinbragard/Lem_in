/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:12:38 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 15:27:09 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <stdio.h>

# define BUFF_SIZE 10000

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_link
{
	struct s_room	*dst;
	int				stream;
}					t_link;

typedef struct		s_room
{
	char			*name;
	t_point			co;
	struct s_link	*link;
	struct s_room	*from;
	int				nb_links;
	int				bfs;
	int				used;
	int				weight;
}					t_room;

typedef struct		s_info
{
	int				nb_rooms;
	int				nb_ants;
	int				nb_univ;
	int				max_path;
	int				error_type;
	int				*nb_cycles;
	int				*ants_repartition;
	unsigned int	hash_size;
	t_room			*start;
	t_room			*end;
}					t_info;

typedef struct		s_path
{
	t_room			**step;
	int				len;
	int				ants;
}					t_path;

typedef struct		s_hash
{
	int				index;
	char			*name;
}					t_hash;

typedef struct		s_ants
{
	int				**tab;
	int				last_ant;
	struct s_ants	*next;
}					t_ants;

t_info				g_info;

unsigned int		hashing_function(char *name);
int					cycle_detector(void);
int					free_hash(t_hash **hash);
int					free_map(t_room **map);
int					free_univ(t_path ***univ);
t_room				*create_map(char **input);
t_room				*create_links(t_room *map, char *input, t_hash *hash);
t_hash				*hash_init(t_room *map);
t_path				**find_partitions(t_room *map);
t_ants				*repartition_init(t_path *univ, int n, int last_ant);
t_ants				*ants_repartition(t_path *univ, int n);
void				sort_univ(t_path **univ);
void				initialize_map(t_room **map);
void				test_streams(t_room **map);
int					clear_map(t_room **map);
void				mark_bfs_streams(void);
void				print_ants(t_ants *ants_repartition, t_path *univ, int n);
void				next_step(t_ants **repartition, t_path *univ, int n);
void				print_ants(t_ants *repartition, t_path *univ, int n);
void				send_ants(t_path *univ, int n);
void				tmp2_to_real(t_room **map);
void				init_room(t_room *room, char **input);
int					bfs_add_regular(t_room **queue, int i, int j, int *end);
int					bfs_add_superpos(t_room **queue, int i, int j, int *end);
int					bfs_add_upflow(t_room **queue, int i, int j, int *end);
int					free_queue(t_room ***queue);
int					init_queue(t_room ***queue, int *end);
int					first_line_type(char *input);
int					get_input(char **input);
int					room_exist_in_queue(t_room **queue, t_room *room);
int					input_prework(char **input);
int					check_links(char *input);
int					check_rooms(char *input);
int					links_prework(t_room **map, char *input, t_hash *hash);
int					ft_usage(int error_type, char *to_free);
int					map_init(t_room **map, char *input);
int					hash_finder(t_hash *hash, char *name);
int					bfs(void);
int					find_multiple_path(t_path **univ, t_room *map, int j);
int					min_paths(void);
int					min_travel_time(t_path **univ);
int					best_univ(t_path **univ);
int					free_univ(t_path ***univ);
int					max_index(int *tab, int len);
int					min_index(int *tab, int len);
int					check_min_max_duration(int *step_len, int nb_routes);
int					copy_path(t_path **univ);
int					path_len(t_room *first);
int					check_path_validity(t_room **tmp);
int					free_ants(t_ants *repartition, int n);
int					init_repart_mallocs(t_ants **rep, int ***tab,
		t_path *univ, int n);
int					new_link(t_room room);
int					lk_del_ids(char *name[2], t_hash *hash, int i, int j);
int					init_links(t_room **map);

#endif

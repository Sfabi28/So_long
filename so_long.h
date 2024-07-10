/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:12:07 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 13:55:42 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pthread.h>
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include "./libft/libft.h"
# include "time.h"
# include <sys/mman.h>

typedef struct s_cowboy_s
{
	void	*s_down_0;
	void	*s_down_1;
	void	*s_down_2;
	void	*s_down_3;
	void	*s_up_0;
	void	*s_up_1;
	void	*s_up_2;
	void	*s_up_3;
	void	*s_left_0;
	void	*s_left_1;
	void	*s_left_2;
	void	*s_left_3;
	void	*s_right_0;
	void	*s_right_1;
	void	*s_right_2;
	void	*s_right_3;
}	t_cowboy_s;

typedef struct s_cowboy_w
{
	void	*w_down_0;
	void	*w_down_1;
	void	*w_down_2;
	void	*w_down_3;
	void	*w_up_0;
	void	*w_up_1;
	void	*w_up_2;
	void	*w_up_3;
	void	*w_left_0;
	void	*w_left_1;
	void	*w_left_2;
	void	*w_left_3;
	void	*w_right_0;
	void	*w_right_1;
	void	*w_right_2;
	void	*w_right_3;
}	t_cowboy_w;

typedef struct s_cowboy_d
{
	void	*d_left_0;
	void	*d_left_1;
	void	*d_left_2;
	void	*d_left_3;
	void	*d_right_0;
	void	*d_right_1;
	void	*d_right_2;
	void	*d_right_3;
}	t_cowboy_d;

typedef struct s_idles
{
	void	*idle_0;
	void	*idle_1;
	void	*idle_2;
	void	*idle_3;
	void	*ghost_idle_0;
	void	*ghost_idle_1;
	void	*ghost_idle_2;
	void	*ghost_idle_3;
	void	*king_lidle_0;
	void	*king_lidle_1;
	void	*king_lidle_2;
	void	*king_lidle_3;
	void	*king_ridle_0;
	void	*king_ridle_1;
	void	*king_ridle_2;
	void	*king_ridle_3;
}	t_idles;

typedef struct s_king_a
{
	void	*king_a_right_0;
	void	*king_a_right_1;
	void	*king_a_right_2;
	void	*king_a_right_3;
	void	*king_a_left_0;
	void	*king_a_left_1;
	void	*king_a_left_2;
	void	*king_a_left_3;
}	t_king_a;

typedef struct s_escape
{
	void	*escape_0;
	void	*escape_1;
	void	*escape_2;
	void	*escape_3;
	void	*escape_4;
	void	*escape_5;
	void	*escape_6;
	void	*escape_7;
	void	*escape_8;
	void	*escape_9;
	void	*escape_10;
	void	*escape_11;							
}	t_escape;

typedef struct s_statics
{
	void	*floor;
	void	*ghost_c;
	void	*teleport_off;
	void	*teleport_on;
	void	*moves;
	void	*wall;
	void	*w_0;
	void	*w_1;
	void	*w_2;
	void	*w_3;
	void	*lost;
	void	*end;
}	t_statics;

typedef struct s_images
{
	struct s_cowboy_s		*shot;
	struct s_cowboy_w		*walk;
	struct s_cowboy_d		*d;
	struct s_idles			*idles;
	struct s_king_a			*king;
	struct s_escape			*escape;
	struct s_statics		*statics;
}	t_images;

typedef struct s_el
{
	int						length;
	int						height;
	int						consumables;
	int						villain;
	int						pos_x;
	int						pos_y;
	int						king_x;
	int						king_y;
	int						*ghost_x;
	int						*ghost_y;
	int						moves;
	void					*ptr;
	void					*win;
	char					**map;
	int						key;
	struct s_images			*images;
	int						**ghost_cords;
	int						prev;
	void					**ar_k;
	void					**ar_w;
	void					**ar_c;
	void					**ar_g;
	int						end;
}	t_el;

/*typedef struct s_thread_data
{
	void			*ptr;
	void			*win;
	char			**map;
	int				length;
	int				height;
	struct s_images	*images;
}	t_thread_data;*/

char		**setmap(char *map_name);
t_el		set_el(int length, int height, int consumables, char *map_name);
int			free_map(char **map);
int			check_form(char **map, int *length, int *height);
int			check_walls(char **map, int height, int length);
int			check_el(char **map, int length, int height,
				int *consumables);
int			check_playable(char **map, t_el el);
int			fill_cell(char **map, int x, int y);
void		set_images(t_el *el);
void		*cp(t_el *el, char *file_name, int *n);
int			set_cowboy_s(t_el *el, int *n);
int			set_cowboy_w(t_el *el, int *n);
int			set_cowboy_d(t_el *el, int *n);
int			set_idles(t_el *el, int *n);
int			set_king_a(t_el *el, int *n);
int			set_escape(t_el *el, int *n);
int			set_static(t_el *el, int *n);
void		destroy_everything(t_el el);
int			*count_elements(char **map, int length, int height);
void		so_long(t_el el);
int			key_press(int keysym, t_el *el);
int			ft_free_all(t_el *el);
void		ft_free_images(t_el *el);
void		game_start(t_el *el);
void		put_images(t_el *el, int i, int j);
void		put_moves(t_el *el);
void		ft_move_left(t_el *el);
void		ft_move_up(t_el *el);
void		ft_move_right(t_el *el);
void		ft_move_down(t_el *el);
void		ft_consumables(t_el *el, int *i);
void		ft_second_move(t_el *el, int prev);
void		**arr_copy(t_el *el);
void		ft_change_image(t_el *el, int prev);
void		ft_activate_exit(t_el *el);
void		**arr_copy_win(t_el *el);
void		ft_win(t_el *el, int x, int y);
void		ft_death(t_el *el, int position, int x_king, int y_king);
void		**arr_copy_lost(t_el *el);
int			king_animations(t_el *el);
void		**arr_king(t_el *el);
void		**arr_walk(t_el *el);
void		**arr_idle(t_el *el);
void		**arr_ghost(t_el *el);
int			ft_king_moves(t_el *el, int nbr);
int			set_el_2(t_el *el);
int			ft_movements(t_el *el, int i);
int			ft_animations(void *arg);
void		set_array(t_el *el);
void		animate_ghosts(t_el *el, int i);
void		locate_ghosts(t_el *el);
void		ft_malloc_error(t_el *el);
void		ft_last_image(t_el *el);
void		ft_change_background(t_el *el);
void		print_moves(t_el *el);
void		ft_while(t_el *el, int *i, int cicle_king);
/*void		**arr_copy_ghost(t_thread_data *thread_data);
void		ghost_idles(t_thread_data *thread_data);
void		*ghost_idles_thread(void *arg);
void		thread_set(t_el *el);*/
#endif

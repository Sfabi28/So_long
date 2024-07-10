/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:55:59 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 11:22:59 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_idles(t_el *el, int *n)
{
	el->images->idles = malloc(sizeof(struct s_cowboy_w));
	if (!el->images->idles)
		return (-1);
	el->images->idles->idle_0 = cp(el, "./img/idle_0.xpm", n);
	el->images->idles->idle_1 = cp(el, "./img/idle_1.xpm", n);
	el->images->idles->idle_2 = cp(el, "./img/idle_2.xpm", n);
	el->images->idles->idle_3 = cp(el, "./img/idle_3.xpm", n);
	el->images->idles->ghost_idle_0 = cp(el, "./img/ghost_idle_0.xpm", n);
	el->images->idles->ghost_idle_1 = cp(el, "./img/ghost_idle_1.xpm", n);
	el->images->idles->ghost_idle_2 = cp(el, "./img/ghost_idle_2.xpm", n);
	el->images->idles->ghost_idle_3 = cp(el, "./img/ghost_idle_3.xpm", n);
	el->images->idles->king_lidle_0 = cp(el, "./img/king_lidle_0.xpm", n);
	el->images->idles->king_lidle_1 = cp(el, "./img/king_lidle_1.xpm", n);
	el->images->idles->king_lidle_2 = cp(el, "./img/king_lidle_2.xpm", n);
	el->images->idles->king_lidle_3 = cp(el, "./img/king_lidle_3.xpm", n);
	el->images->idles->king_ridle_0 = cp(el, "./img/king_ridle_0.xpm", n);
	el->images->idles->king_ridle_1 = cp(el, "./img/king_ridle_1.xpm", n);
	el->images->idles->king_ridle_2 = cp(el, "./img/king_ridle_2.xpm", n);
	el->images->idles->king_ridle_3 = cp(el, "./img/king_ridle_3.xpm", n);
	if ((el->images->idles->king_ridle_3) == NULL)
		return (-1);
	return (0);
}

int	set_king_a(t_el *el, int *n)
{
	el->images->king = malloc(sizeof(struct s_cowboy_w));
	if (!el->images->king)
		return (-1);
	el->images->king->king_a_right_0 = cp(el, "./img/king_a_right_0.xpm", n);
	el->images->king->king_a_right_1 = cp(el, "./img/king_a_right_1.xpm", n);
	el->images->king->king_a_right_2 = cp(el, "./img/king_a_right_2.xpm", n);
	el->images->king->king_a_right_3 = cp(el, "./img/king_a_right_3.xpm", n);
	el->images->king->king_a_left_0 = cp(el, "./img/king_a_left_0.xpm", n);
	el->images->king->king_a_left_1 = cp(el, "./img/king_a_left_1.xpm", n);
	el->images->king->king_a_left_2 = cp(el, "./img/king_a_left_2.xpm", n);
	el->images->king->king_a_left_3 = cp(el, "./img/king_a_left_3.xpm", n);
	if ((el->images->king->king_a_left_3) == NULL)
		return (-1);
	return (0);
}

int	set_escape(t_el *el, int *n)
{
	el->images->escape = malloc(sizeof(struct s_cowboy_w));
	if (!el->images->escape)
		return (-1);
	el->images->escape->escape_0 = cp(el, "./img/escape_0.xpm", n);
	el->images->escape->escape_1 = cp(el, "./img/escape_1.xpm", n);
	el->images->escape->escape_2 = cp(el, "./img/escape_2.xpm", n);
	el->images->escape->escape_3 = cp(el, "./img/escape_3.xpm", n);
	el->images->escape->escape_4 = cp(el, "./img/escape_4.xpm", n);
	el->images->escape->escape_5 = cp(el, "./img/escape_5.xpm", n);
	el->images->escape->escape_6 = cp(el, "./img/escape_6.xpm", n);
	el->images->escape->escape_7 = cp(el, "./img/escape_7.xpm", n);
	el->images->escape->escape_8 = cp(el, "./img/escape_8.xpm", n);
	el->images->escape->escape_9 = cp(el, "./img/escape_9.xpm", n);
	el->images->escape->escape_10 = cp(el, "./img/escape_10.xpm", n);
	el->images->escape->escape_11 = cp(el, "./img/escape_11.xpm", n);
	if ((el->images->escape->escape_11) == NULL)
		return (-1);
	return (0);
}

int	set_static(t_el *el, int *n)
{
	int	i;
	int	j;

	i = 16;
	j = 192;
	el->images->statics = malloc(sizeof(struct s_cowboy_w));
	if (!el->images->statics)
		return (-1);
	el->images->statics->floor = cp(el, "./img/floor.xpm", n);
	el->images->statics->ghost_c = cp(el, "./img/ghost_catched.xpm", n);
	el->images->statics->teleport_off = cp(el, "./img/teleport_off.xpm", n);
	el->images->statics->teleport_on = cp(el, "./img/teleport_on.xpm", n);
	el->images->statics->wall = cp(el, "./img/wall.xpm", n);
	el->images->statics->w_0 = cp(el, "./img/win_0.xpm", &j);
	el->images->statics->w_1 = cp(el, "./img/win_1.xpm", &j);
	el->images->statics->w_2 = cp(el, "./img/win_2.xpm", &j);
	el->images->statics->w_3 = cp(el, "./img/win_3.xpm", &j);
	el->images->statics->lost = cp(el, "./img/lost.xpm", &j);
	el->images->statics->end = cp(el, "./img/end.xpm", &i);
	el->images->statics->moves = cp(el, "./img/moves.xpm", &i);
	if ((el->images->statics->moves) == NULL)
		return (-1);
	return (0);
}

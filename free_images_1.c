/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:57:21 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 11:21:39 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dl(t_el *el, void *img)
{
	if (img)
		mlx_destroy_image(el->ptr, img);
}

static void	ft_free_images_4(t_el *el)
{
	dl(el, el->images->escape->escape_8);
	dl(el, el->images->escape->escape_9);
	dl(el, el->images->escape->escape_10);
	dl(el, el->images->escape->escape_11);
	dl(el, el->images->statics->floor);
	dl(el, el->images->statics->ghost_c);
	dl(el, el->images->statics->teleport_off);
	dl(el, el->images->statics->teleport_on);
	dl(el, el->images->statics->moves);
	dl(el, el->images->statics->w_0);
	dl(el, el->images->statics->w_1);
	dl(el, el->images->statics->w_2);
	dl(el, el->images->statics->w_3);
	dl(el, el->images->statics->lost);
	dl(el, el->images->statics->wall);
	dl(el, el->images->statics->end);
	free(el->images->shot);
	free(el->images->walk);
	free(el->images->d);
	free(el->images->idles);
	free(el->images->king);
	free(el->images->escape);
	free(el->images->statics);
	free(el->images);
}

static void	ft_free_images_3(t_el *el)
{
	dl(el, el->images->idles->king_lidle_0);
	dl(el, el->images->idles->king_lidle_1);
	dl(el, el->images->idles->king_lidle_2);
	dl(el, el->images->idles->king_lidle_3);
	dl(el, el->images->idles->king_ridle_0);
	dl(el, el->images->idles->king_ridle_1);
	dl(el, el->images->idles->king_ridle_2);
	dl(el, el->images->idles->king_ridle_3);
	dl(el, el->images->king->king_a_right_0);
	dl(el, el->images->king->king_a_right_1);
	dl(el, el->images->king->king_a_right_2);
	dl(el, el->images->king->king_a_right_3);
	dl(el, el->images->king->king_a_left_0);
	dl(el, el->images->king->king_a_left_1);
	dl(el, el->images->king->king_a_left_2);
	dl(el, el->images->king->king_a_left_3);
	dl(el, el->images->escape->escape_0);
	dl(el, el->images->escape->escape_1);
	dl(el, el->images->escape->escape_2);
	dl(el, el->images->escape->escape_3);
	dl(el, el->images->escape->escape_4);
	dl(el, el->images->escape->escape_5);
	dl(el, el->images->escape->escape_6);
	dl(el, el->images->escape->escape_7);
	ft_free_images_4(el);
}

static void	ft_free_images_2(t_el *el)
{
	dl(el, el->images->walk->w_left_0);
	dl(el, el->images->walk->w_left_1);
	dl(el, el->images->walk->w_left_2);
	dl(el, el->images->walk->w_left_3);
	dl(el, el->images->walk->w_right_0);
	dl(el, el->images->walk->w_right_1);
	dl(el, el->images->walk->w_right_2);
	dl(el, el->images->walk->w_right_3);
	dl(el, el->images->d->d_left_0);
	dl(el, el->images->d->d_left_1);
	dl(el, el->images->d->d_left_2);
	dl(el, el->images->d->d_left_3);
	dl(el, el->images->d->d_right_0);
	dl(el, el->images->d->d_right_1);
	dl(el, el->images->d->d_right_2);
	dl(el, el->images->d->d_right_3);
	dl(el, el->images->idles->idle_0);
	dl(el, el->images->idles->idle_1);
	dl(el, el->images->idles->idle_2);
	dl(el, el->images->idles->idle_3);
	dl(el, el->images->idles->ghost_idle_0);
	dl(el, el->images->idles->ghost_idle_1);
	dl(el, el->images->idles->ghost_idle_2);
	dl(el, el->images->idles->ghost_idle_3);
	ft_free_images_3(el);
}

void	ft_free_images(t_el *el)
{
	dl(el, el->images->shot->s_down_0);
	dl(el, el->images->shot->s_down_1);
	dl(el, el->images->shot->s_down_2);
	dl(el, el->images->shot->s_down_3);
	dl(el, el->images->shot->s_up_0);
	dl(el, el->images->shot->s_up_1);
	dl(el, el->images->shot->s_up_2);
	dl(el, el->images->shot->s_up_3);
	dl(el, el->images->shot->s_left_0);
	dl(el, el->images->shot->s_left_1);
	dl(el, el->images->shot->s_left_2);
	dl(el, el->images->shot->s_left_3);
	dl(el, el->images->shot->s_right_0);
	dl(el, el->images->shot->s_right_1);
	dl(el, el->images->shot->s_right_2);
	dl(el, el->images->shot->s_right_3);
	dl(el, el->images->walk->w_down_0);
	dl(el, el->images->walk->w_down_1);
	dl(el, el->images->walk->w_down_2);
	dl(el, el->images->walk->w_down_3);
	dl(el, el->images->walk->w_up_0);
	dl(el, el->images->walk->w_up_1);
	dl(el, el->images->walk->w_up_2);
	dl(el, el->images->walk->w_up_3);
	ft_free_images_2(el);
}

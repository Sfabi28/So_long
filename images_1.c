/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:34:55 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/26 15:44:22 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_el *el)
{
	int	n;
	int	ret;

	ret = 0;
	el->images = malloc(sizeof(struct s_images));
	if (!el->images)
		ft_malloc_error(el);
	n = 64;
	ret += set_cowboy_s(el, &n);
	ret += set_cowboy_w(el, &n);
	ret += set_cowboy_d(el, &n);
	ret += set_idles(el, &n);
	ret += set_king_a(el, &n);
	ret += set_escape(el, &n);
	ret += set_static(el, &n);
	if (ret != 0)
		ft_malloc_error(el);
}

void	*cp(t_el *el, char *file_name, int *n)
{
	return (mlx_xpm_file_to_image(el->ptr, file_name, n, n));
}

int	set_cowboy_s(t_el *el, int *n)
{
	el->images->shot = malloc(sizeof(struct s_cowboy_s));
	if (!el->images->shot)
		return (-1);
	el->images->shot->s_down_0 = cp(el, "./img/s_down_0.xpm", n);
	el->images->shot->s_down_1 = cp(el, "./img/s_down_1.xpm", n);
	el->images->shot->s_down_2 = cp(el, "./img/s_down_2.xpm", n);
	el->images->shot->s_down_3 = cp(el, "./img/s_down_3.xpm", n);
	el->images->shot->s_up_0 = cp(el, "./img/s_up_0.xpm", n);
	el->images->shot->s_up_1 = cp(el, "./img/s_up_1.xpm", n);
	el->images->shot->s_up_2 = cp(el, "./img/s_up_2.xpm", n);
	el->images->shot->s_up_3 = cp(el, "./img/s_up_3.xpm", n);
	el->images->shot->s_left_0 = cp(el, "./img/s_left_0.xpm", n);
	el->images->shot->s_left_1 = cp(el, "./img/s_left_1.xpm", n);
	el->images->shot->s_left_2 = cp(el, "./img/s_left_2.xpm", n);
	el->images->shot->s_left_3 = cp(el, "./img/s_left_3.xpm", n);
	el->images->shot->s_right_0 = cp(el, "./img/s_right_0.xpm", n);
	el->images->shot->s_right_1 = cp(el, "./img/s_right_1.xpm", n);
	el->images->shot->s_right_2 = cp(el, "./img/s_right_2.xpm", n);
	el->images->shot->s_right_3 = cp(el, "./img/s_right_3.xpm", n);
	if (!el->images->shot->s_right_3)
		return (-1);
	return (0);
}

int	set_cowboy_w(t_el *el, int *n)
{
	el->images->walk = malloc(sizeof(struct s_cowboy_w));
	if (!el->images->walk)
		return (-1);
	el->images->walk->w_down_0 = cp(el, "./img/w_down_0.xpm", n);
	el->images->walk->w_down_1 = cp(el, "./img/w_down_1.xpm", n);
	el->images->walk->w_down_2 = cp(el, "./img/w_down_2.xpm", n);
	el->images->walk->w_down_3 = cp(el, "./img/w_down_3.xpm", n);
	el->images->walk->w_up_0 = cp(el, "./img/w_up_0.xpm", n);
	el->images->walk->w_up_1 = cp(el, "./img/w_up_1.xpm", n);
	el->images->walk->w_up_2 = cp(el, "./img/w_up_2.xpm", n);
	el->images->walk->w_up_3 = cp(el, "./img/w_up_3.xpm", n);
	el->images->walk->w_left_0 = cp(el, "./img/w_left_0.xpm", n);
	el->images->walk->w_left_1 = cp(el, "./img/w_left_1.xpm", n);
	el->images->walk->w_left_2 = cp(el, "./img/w_left_2.xpm", n);
	el->images->walk->w_left_3 = cp(el, "./img/w_left_3.xpm", n);
	el->images->walk->w_right_0 = cp(el, "./img/w_right_0.xpm", n);
	el->images->walk->w_right_1 = cp(el, "./img/w_right_1.xpm", n);
	el->images->walk->w_right_2 = cp(el, "./img/w_right_2.xpm", n);
	el->images->walk->w_right_3 = cp(el, "./img/w_right_3.xpm", n);
	if ((el->images->walk->w_right_3) == NULL)
		return (-1);
	return (0);
}

int	set_cowboy_d(t_el *el, int *n)
{
	el->images->d = malloc(sizeof(struct s_cowboy_w));
	if (!el->images->d)
		return (-1);
	el->images->d->d_left_0 = cp(el, "./img/d_left_0.xpm", n);
	el->images->d->d_left_1 = cp(el, "./img/d_left_1.xpm", n);
	el->images->d->d_left_2 = cp(el, "./img/d_left_2.xpm", n);
	el->images->d->d_left_3 = cp(el, "./img/d_left_3.xpm", n);
	el->images->d->d_right_0 = cp(el, "./img/d_right_0.xpm", n);
	el->images->d->d_right_1 = cp(el, "./img/d_right_1.xpm", n);
	el->images->d->d_right_2 = cp(el, "./img/d_right_2.xpm", n);
	el->images->d->d_right_3 = cp(el, "./img/d_right_3.xpm", n);
	if ((el->images->d->d_right_3) == NULL)
		return (-1);
	return (0);
}

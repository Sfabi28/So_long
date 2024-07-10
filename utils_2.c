/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:46:21 by sfabi             #+#    #+#             */
/*   Updated: 2024/05/31 11:40:40 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_all(t_el *el)
{
	if (el->map)
		free_map(el->map);
	if (el->images)
		ft_free_images(el);
	if (el->win)
		mlx_destroy_window(el->ptr, el->win);
	if (el->ptr)
	{
		mlx_destroy_display(el->ptr);
		free (el->ptr);
	}
	if (el->ar_k)
		free(el->ar_k);
	if (el->ar_w)
		free(el->ar_w);
	if (el->ar_c)
		free(el->ar_c);
	if (el->ar_g)
		free(el->ar_g);
	if (el->ghost_x)
		free(el->ghost_x);
	if (el->ghost_y)
		free(el->ghost_y);
	exit(0);
	return (0);
}

int	key_press(int keysym, t_el *el)
{
	if (el->end == 0)
	{
		if (keysym == XK_Escape)
		{
			ft_free_all(el);
			exit(0);
		}
		if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
			el->key = 0;
		else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
			el->key = 1;
		else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
			el->key = 2;
		else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
			el->key = 3;
		ft_animations(el);
		print_moves(el);
		return (0);
	}
	if (keysym != NoSymbol)
		ft_free_all(el);
	return (0);
}

void	put_moves(t_el *el)
{
	int	i;

	i = 0;
	while (i / 4 < el->length)
	{
		mlx_put_image_to_window(el->ptr, el->win,
			el->images->statics->moves, i * 16, 0);
		i++;
	}
	mlx_string_put(el->ptr, el->win, 32, 12, 0xFFFFFF, "moves:");
}

void	put_images(t_el *el, int i, int j)
{
	if (el->map[i][j] == '0')
		mlx_put_image_to_window(el->ptr, el->win,
			el->images->statics->floor, j * 64, (i * 64) + 16);
	else if (el->map[i][j] == '1')
		mlx_put_image_to_window(el->ptr, el->win,
			el->images->statics->wall, j * 64, (i * 64) + 16);
	else if (el->map[i][j] == 'V')
		mlx_put_image_to_window(el->ptr, el->win,
			el->images->idles->king_ridle_0, j * 64, (i * 64) + 16);
	else if (el->map[i][j] == 'P')
		mlx_put_image_to_window(el->ptr, el->win,
			el->images->idles->idle_0, j * 64, (i * 64) + 16);
	else if (el->map[i][j] == 'C')
		mlx_put_image_to_window(el->ptr, el->win,
			el->images->idles->ghost_idle_0, j * 64, (i * 64) + 16);
	else if (el->map[i][j] == 'E')
		mlx_put_image_to_window(el->ptr, el->win,
			el->images->statics->teleport_off, j * 64, (i * 64) + 16);
}

void	ft_change_image(t_el *el, int prev)
{
	if (prev == 1 || prev == 3)
	{
		mlx_put_image_to_window(el->ptr, el->win,
			el->images->statics->floor, el->pos_x * 64, el->pos_y * 64 + 16);
		el->map[el->pos_y][el->pos_x] = '0';
		el->pos_x = el->pos_x -2 + prev;
		mlx_put_image_to_window(el->ptr, el->win, el->images->idles->idle_0,
			el->pos_x * 64, el->pos_y * 64 + 16);
		el->map[el->pos_y][el->pos_x] = 'P';
	}
	if (prev == 2 || prev == 4)
	{
		mlx_put_image_to_window(el->ptr, el->win,
			el->images->statics->floor, el->pos_x * 64, el->pos_y * 64 + 16);
		el->map[el->pos_y][el->pos_x] = '0';
		el->pos_y = el->pos_y -3 + prev;
		mlx_put_image_to_window(el->ptr, el->win,
			el->images->idles->idle_0, el->pos_x * 64, el->pos_y * 64 + 16);
		el->map[el->pos_y][el->pos_x] = 'P';
	}
}

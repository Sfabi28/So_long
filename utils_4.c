/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:36:18 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 13:47:36 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_ghosts(t_el *el)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	el->ghost_x = malloc(sizeof(int) * 100);
	if (!el->ghost_x)
		ft_malloc_error(el);
	el->ghost_y = malloc(sizeof(int) * 100);
	if (!el->ghost_y)
		ft_malloc_error(el);
	i = 0;
	while (++i < el->height - 1)
	{
		j = 0;
		while (++j < el->length - 1)
		{
			if (el->map[i][j] == 'C')
			{
				el->ghost_x[count] = j;
				el->ghost_y[count] = i;
				count++;
			}
		}
	}
}

void	animate_ghosts(t_el *el, int i)
{
	int	count;

	count = 0;
	while (count < el->consumables)
	{
		if (el->map[el->ghost_y[count]][el->ghost_x[count]] == 'C')
			mlx_put_image_to_window(el->ptr, el->win, el->ar_g[i],
				(el->ghost_x[count]) * 64, (el->ghost_y[count]) * 64 + 16);
		count++;
	}
}

void	ft_malloc_error(t_el *el)
{
	perror("Error!\nmemory allocation error");
	ft_free_all(el);
	exit(-1);
}

void	ft_last_image(t_el *el)
{
	int	x;
	int	y;

	if (el->villain != 2)
		ft_change_background(el);
	x = (el->length * 64 - 192) / 2;
	y = (el->height * 64 - 160) / 2;
	if (el->end == 2)
		mlx_put_image_to_window(el->ptr, el->win, el->images->statics->lost,
			x, y);
	if (el->end == 2)
		return ;
	mlx_put_image_to_window(el->ptr, el->win, el->images->statics->w_0, x, y);
	mlx_do_sync(el->ptr);
	usleep(200000);
	mlx_put_image_to_window(el->ptr, el->win, el->images->statics->w_1, x, y);
	mlx_do_sync(el->ptr);
	usleep(200000);
	mlx_put_image_to_window(el->ptr, el->win, el->images->statics->w_2, x, y);
	mlx_do_sync(el->ptr);
	usleep(200000);
	mlx_put_image_to_window(el->ptr, el->win, el->images->statics->w_3, x, y);
	mlx_do_sync(el->ptr);
	usleep(200000);
}

void	ft_change_background(t_el *el)
{
	int	i;
	int	j;

	i = -1;
	while (++i < el->height * 5)
	{
		j = -1;
		while (++j < el->length * 4)
		{
			mlx_put_image_to_window(el->ptr, el->win,
				el->images->statics->end, j * 16, i * 16);
		}
	}
	el->villain = 2;
	put_moves(el);
	print_moves(el);
}

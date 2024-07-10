/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:03:29 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 13:49:41 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_el *el, int x, int y)
{
	void	**arr;
	int		i;

	i = -1;
	arr = arr_copy_win(el);
	while (++i < 4)
	{
		mlx_put_image_to_window(el->ptr, el->win, el->ar_w[el->key * 4 + i],
			(el->pos_x) * 64, (el->pos_y) * 64 + 16);
		mlx_do_sync(el->ptr);
		usleep(150000);
	}
	i = -1;
	mlx_put_image_to_window(el->ptr, el->win, el->images->statics->floor,
		(el->pos_x) * 64, (el->pos_y) * 64 + 16);
	while (++i < 12)
	{
		mlx_put_image_to_window(el->ptr, el->win, arr[i],
			x * 64, y * 64 + 16);
		mlx_do_sync(el->ptr);
		usleep(300000);
	}
	free(arr);
	el->end = 1;
	el->key = 4;
}

void	**arr_copy_win(t_el *el)
{
	void	**arr;

	arr = malloc(16 * sizeof(void *));
	if (!arr)
		ft_malloc_error(el);
	arr[0] = el->images->escape->escape_0;
	arr[1] = el->images->escape->escape_1;
	arr[2] = el->images->escape->escape_2;
	arr[3] = el->images->escape->escape_3;
	arr[4] = el->images->escape->escape_4;
	arr[5] = el->images->escape->escape_5;
	arr[6] = el->images->escape->escape_6;
	arr[7] = el->images->escape->escape_7;
	arr[8] = el->images->escape->escape_8;
	arr[9] = el->images->escape->escape_9;
	arr[10] = el->images->escape->escape_10;
	arr[11] = el->images->escape->escape_11;
	return (arr);
}

void	ft_death(t_el *el, int position, int x_king, int y_king)
{
	void	**arr;
	int		i;

	i = (position - 1) * 4;
	arr = arr_copy_lost(el);
	while (i < (position - 1) * 4 + 4)
	{
		mlx_put_image_to_window(el->ptr, el->win, arr[i],
			(x_king) * 64, (y_king) * 64 + 16);
		mlx_do_sync(el->ptr);
		mlx_put_image_to_window(el->ptr, el->win, arr[i + 8],
			(el->pos_x) * 64, (el->pos_y) * 64 + 16);
		mlx_do_sync(el->ptr);
		usleep(250000);
		i++;
	}
	free(arr);
	el->end = 2;
	el->key = 4;
}

void	**arr_copy_lost(t_el *el)
{
	void	**arr;

	arr = malloc(16 * sizeof(void *));
	if (!arr)
		ft_malloc_error(el);
	arr[0] = el->images->king->king_a_right_0;
	arr[1] = el->images->king->king_a_right_1;
	arr[2] = el->images->king->king_a_right_2;
	arr[3] = el->images->king->king_a_right_3;
	arr[4] = el->images->king->king_a_left_0;
	arr[5] = el->images->king->king_a_left_1;
	arr[6] = el->images->king->king_a_left_2;
	arr[7] = el->images->king->king_a_left_3;
	arr[8] = el->images->d->d_left_0;
	arr[9] = el->images->d->d_left_1;
	arr[10] = el->images->d->d_left_2;
	arr[11] = el->images->d->d_left_3;
	arr[12] = el->images->d->d_right_0;
	arr[13] = el->images->d->d_right_1;
	arr[14] = el->images->d->d_right_2;
	arr[15] = el->images->d->d_right_3;
	return (arr);
}

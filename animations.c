/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:14:23 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 13:56:10 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_animations(void *arg)
{
	int		i;
	int		cicle_king;
	t_el	*el;

	el = (t_el *) arg;
	if (el->end != 0)
		return (ft_last_image(el), 0);
	i = 0;
	cicle_king = -1;
	if (el->villain == 1)
		cicle_king = king_animations(el);
	while (i < 4 && el->end == 0)
	{
		ft_while(el, &i, cicle_king);
		i++;
	}
	if (ft_movements(el, el->key) != -1)
	{
		ft_change_image(el, el->key + 1);
		el->moves++;
	}
	el->key = 4;
	return (0);
}

void	**arr_walk(t_el *el)
{
	void	**arr;

	arr = malloc(16 * sizeof(void *));
	if (!arr)
		ft_malloc_error(el);
	arr[0] = el->images->walk->w_left_0;
	arr[1] = el->images->walk->w_left_1;
	arr[2] = el->images->walk->w_left_2;
	arr[3] = el->images->walk->w_left_3;
	arr[4] = el->images->walk->w_up_0;
	arr[5] = el->images->walk->w_up_1;
	arr[6] = el->images->walk->w_up_2;
	arr[7] = el->images->walk->w_up_3;
	arr[8] = el->images->walk->w_right_0;
	arr[9] = el->images->walk->w_right_1;
	arr[10] = el->images->walk->w_right_2;
	arr[11] = el->images->walk->w_right_3;
	arr[12] = el->images->walk->w_down_0;
	arr[13] = el->images->walk->w_down_1;
	arr[14] = el->images->walk->w_down_2;
	arr[15] = el->images->walk->w_down_3;
	return (arr);
}

void	**arr_king(t_el *el)
{
	void	**arr;

	arr = malloc(8 * sizeof(void *));
	if (!arr)
		ft_malloc_error(el);
	arr[0] = el->images->idles->king_lidle_0;
	arr[1] = el->images->idles->king_lidle_1;
	arr[2] = el->images->idles->king_lidle_2;
	arr[3] = el->images->idles->king_lidle_3;
	arr[4] = el->images->idles->king_ridle_0;
	arr[5] = el->images->idles->king_ridle_1;
	arr[6] = el->images->idles->king_ridle_2;
	arr[7] = el->images->idles->king_ridle_3;
	return (arr);
}

void	ft_while(t_el *el, int *i, int cicle_king)
{
	animate_ghosts(el, *i);
	if (el->key == 4)
		mlx_put_image_to_window(el->ptr, el->win, el->ar_c[*i],
			(el->pos_x) * 64, (el->pos_y) * 64 + 16);
	else if (el->key != 4 && ft_movements(el, el->key) == 10)
		ft_consumables(el, i);
	else if (el->key != 4 && ft_movements(el, el->key) != -1)
		mlx_put_image_to_window(el->ptr, el->win, el->ar_w[el->key * 4 + *i],
			(el->pos_x) * 64, (el->pos_y) * 64 + 16);
	if (cicle_king != -1)
		mlx_put_image_to_window(el->ptr, el->win, el->ar_k[cicle_king + *i],
			(el->king_x) * 64, (el->king_y) * 64 + 16);
	mlx_do_sync(el->ptr);
	usleep(150000);
}

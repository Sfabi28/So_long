/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:46:20 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 09:32:34 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_consumables(t_el *el, int *i)
{
	void	**arr;

	arr = arr_copy(el);
	mlx_put_image_to_window(el->ptr, el->win, arr[el->key * 4 + *i],
		(el->pos_x) * 64, (el->pos_y) * 64 + 16);
	if (*i == 3)
	{
		el->consumables--;
		*i = 0;
		if (el->key == 0)
			el->map[el->pos_y][el->pos_x - 1] = '0';
		else if (el->key == 1)
			el->map[el->pos_y - 1][el->pos_x] = '0';
		else if (el->key == 2)
			el->map[el->pos_y][el->pos_x + 1] = '0';
		else if (el->key == 3)
			el->map[el->pos_y + 1][el->pos_x] = '0';
	}
	if (el->consumables == 0)
		ft_activate_exit(el);
	free(arr);
}

void	**arr_copy(t_el *el)
{
	void	**arr;

	arr = malloc(16 * sizeof(void *));
	if (!arr)
		ft_malloc_error(el);
	arr[0] = el->images->shot->s_left_0;
	arr[1] = el->images->shot->s_left_1;
	arr[2] = el->images->shot->s_left_2;
	arr[3] = el->images->shot->s_left_3;
	arr[4] = el->images->shot->s_up_0;
	arr[5] = el->images->shot->s_up_1;
	arr[6] = el->images->shot->s_up_2;
	arr[7] = el->images->shot->s_up_3;
	arr[8] = el->images->shot->s_right_0;
	arr[9] = el->images->shot->s_right_1;
	arr[10] = el->images->shot->s_right_2;
	arr[11] = el->images->shot->s_right_3;
	arr[12] = el->images->shot->s_down_0;
	arr[13] = el->images->shot->s_down_1;
	arr[14] = el->images->shot->s_down_2;
	arr[15] = el->images->shot->s_down_3;
	return (arr);
}

void	ft_activate_exit(t_el *el)
{
	int	i;
	int	j;

	i = 0;
	while (++i < el->height - 1)
	{
		j = 0;
		while (++j < el->length - 1)
		{
			if (el->map[i][j] == 'E')
			{
				mlx_put_image_to_window(el->ptr, el->win,
					el->images->statics->teleport_on,
					j * 64, i * 64 + 16);
				return ;
			}
		}
	}
}

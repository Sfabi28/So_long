/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:43:50 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 13:47:03 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_el_2(t_el *el)
{
	int	i;
	int	j;

	i = 0;
	while (++i < el->height - 1)
	{
		j = 0;
		while (++j < el->length - 1)
		{
			if (el->map[i][j] == 'V')
			{
				el->king_x = j;
				el->king_y = i;
				break ;
			}
		}
	}
	el->key = 4;
	el->end = 0;
	return (15);
}

void	set_array(t_el *el)
{
	el->ar_k = arr_king(el);
	el->ar_w = arr_walk(el);
	el->ar_c = arr_idle(el);
	el->ar_g = arr_ghost(el);
}

void	**arr_idle(t_el *el)
{
	void	**arr;

	arr = malloc(8 * sizeof(void *));
	if (!arr)
		ft_malloc_error(el);
	arr[0] = el->images->idles->idle_0;
	arr[1] = el->images->idles->idle_1;
	arr[2] = el->images->idles->idle_2;
	arr[3] = el->images->idles->idle_3;
	return (arr);
}

void	**arr_ghost(t_el *el)
{
	void	**arr;

	arr = malloc(8 * sizeof(void *));
	if (!arr)
		ft_malloc_error(el);
	arr[0] = el->images->idles->ghost_idle_0;
	arr[1] = el->images->idles->ghost_idle_1;
	arr[2] = el->images->idles->ghost_idle_2;
	arr[3] = el->images->idles->ghost_idle_3;
	return (arr);
}

void	print_moves(t_el *el)
{
	char	*prev_move;
	char	*move;

	if (el->moves > 0)
	{
		prev_move = ft_itoa(el->moves - 1);
		if (!prev_move)
			ft_malloc_error(el);
		mlx_string_put(el->ptr, el->win, 70, 12, 0x464646, prev_move);
		free(prev_move);
	}
	move = ft_itoa(el->moves);
	if (!move)
		ft_malloc_error(el);
	mlx_string_put(el->ptr, el->win, 70, 12, 0xFFFFFF, move);
	free(move);
}

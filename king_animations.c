/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   king_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:17:50 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 10:38:12 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	king_animations(t_el *el)
{
	int			number;
	int			res;

	srandom(time(NULL));
	number = random() % 5;
	if (el->prev > 10)
	{
		number = number % 2;
		el->prev = 2;
		res = ft_king_moves(el, number);
		return (res);
	}
	res = ft_king_moves(el, number);
	return (res);
}

int	ft_king_moves(t_el *el, int nbr)
{
	char	around[4];

	around[0] = el->map[el->king_y][el->king_x - 1];
	around[1] = el->map[el->king_y - 1][el->king_x];
	around[2] = el->map[el->king_y][el->king_x + 1];
	around[3] = el->map[el->king_y + 1][el->king_x];
	if (around[0] == 'P')
		return (ft_death(el, 2, el->king_x, el->king_y), -1);
	if (around[2] == 'P')
		return (ft_death(el, 1, el->king_x, el->king_y), -1);
	if (nbr == 0 && around[0] != '0')
		nbr = 2;
	else if (nbr == 1 && around[1] != '0')
		nbr = 3;
	else if (nbr == 2 && around[2] != '0')
		nbr = 0;
	else if (nbr == 3 && around[3] != '0')
		nbr = 1;
	if (nbr == 0 && around[0] == '0')
	{
		if (el->prev == 2)
			return (el->prev = 0, 0);
		else
		{
			mlx_put_image_to_window(el->ptr, el->win, el->images->statics->floor,
				el->king_x * 64, el->king_y * 64 + 16);
			el->map[el->king_y][el->king_x] = '0';
			el->king_x--;
			el->map[el->king_y][el->king_x] = 'V';
			return (0);
		}
		el->prev = 0;
		return (-1);
	}
	else if (nbr == 1 && around[1] == '0')
	{
		mlx_put_image_to_window(el->ptr, el->win, el->images->statics->floor,
			el->king_x * 64, el->king_y * 64 + 16);
		el->map[el->king_y][el->king_x] = '0';
		el->king_y--;
		el->map[el->king_y][el->king_x] = 'V';
		return (el->prev * 2);
	}
	else if (nbr == 2 && around[2] == '0')
	{
		if (el->prev == 0)
			return (el->prev = 2, 2);
		else
		{
			mlx_put_image_to_window(el->ptr, el->win, el->images->statics->floor,
				el->king_x * 64, el->king_y * 64 + 16);
			el->map[el->king_y][el->king_x] = '0';
			el->king_x++;
			el->map[el->king_y][el->king_x] = 'V';
			return (4);
		}
		el->prev = 0;
		return (-1);
	}
	else if (nbr == 3 && around[3] == '0')
	{
		mlx_put_image_to_window(el->ptr, el->win, el->images->statics->floor,
			el->king_x * 64, el->king_y * 64 + 16);
		el->map[el->king_y][el->king_x] = '0';
		el->king_y++;
		el->map[el->king_y][el->king_x] = 'V';
		return (el->prev * 2);
	}
	else
		return (el->prev * 2);
}

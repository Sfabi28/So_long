/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:29:26 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 13:49:05 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_movements(t_el *el, int i)
{
	int	x;
	int	y;

	if (i == 0 || i == 2)
	{
		y = 0;
		x = i - 1;
	}
	if (i == 1 || i == 3)
	{
		x = 0;
		y = i - 2;
	}
	if (i == 4)
		return (-1);
	if (el->map[el->pos_y + y][el->pos_x + x] == 'V')
		return (-1);
	if ((el->map[el->pos_y + y][el->pos_x + x] == '1') ||
		(el->map[el->pos_y + y][el->pos_x + x] == 'E' && el->consumables != 0))
		return (-1);
	if (el->map[el->pos_y + y][el->pos_x + x] == 'C')
		return (10);
	if (el->map[el->pos_y + y][el->pos_x + x] == 'E' && el->consumables == 0)
		ft_win(el, el->pos_x + x, el->pos_y + y);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:17:04 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/17 11:37:50 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_form(char **map, int *length, int *height)
{
	int	right_length;

	while (map[*height])
	{
		*length = ft_strlen(map[*height]);
		if (*height == 0)
			right_length = *length;
		if (*length != right_length)
			return (-1);
		(*height)++;
	}
	return (0);
}

int	check_walls(char **map, int length, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
		{
			j = 0;
			while (j < length)
			{
				if (map[i][j] != '1')
					return (-1);
				j++;
			}
		}
		else if (map[i][0] != '1' || map[i][length - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_el(char **map, int length, int height, int *c)
{
	int	el[2];
	int	i;
	int	j;

	i = 0;
	el[0] = 0;
	el[1] = 0;
	while (++i < height - 1)
	{
		j = 0;
		while (++j < length - 1)
		{
			if (map[i][j] == 'P')
				el[0]++;
			else if (map[i][j] == 'E')
				el[1]++;
			else if (map[i][j] == 'C')
				(*c)++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'V')
				return (-1);
		}
	}
	if (el[0] != 1 || el[1] != 1 || *c <= 0)
		return (-1);
	return (0);
}

int	check_playable(char **map, t_el el)
{
	int		result;
	int		i;
	int		j;

	result = fill_cell(map, el.pos_x, el.pos_y);
	i = 0;
	if (result == 0)
		return (free_map(map));
	while (i < el.height)
	{
		j = 0;
		while (j < el.length)
		{
			if (map[i][j] == 'C')
				return (free_map(map));
			j++;
		}
		i++;
	}
	free_map(map);
	return (0);
}

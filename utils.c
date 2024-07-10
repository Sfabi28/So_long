/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:53:10 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/22 15:24:35 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**setmap(char *map_name)
{
	char	**map;
	char	*line;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 1)
	{
		perror("invalid map name");
		exit (-1);
	}
	line = ft_calloc(5001, sizeof(char));
	if (!line)
		return (NULL);
	read(fd, line, 5000);
	close(fd);
	map = ft_split(line, '\n');
	if (!map)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (map);
}

t_el	set_el(int length, int height, int consumables, char *map_name)
{
	t_el	el;
	int		*arr;

	el.map = setmap(map_name);
	if (!el.map)
		perror("Error!\nmemory allocation error");
	if (!el.map)
		exit (-1);
	el.length = length;
	el.height = height;
	el.consumables = consumables;
	el.moves = 0;
	arr = count_elements(el.map, length, height);
	if ((arr) == NULL)
		perror("Error!\nmemory allocation error");
	if ((arr) == NULL)
		exit (free_map(el.map));
	el.pos_x = arr[1];
	el.pos_y = arr[0];
	el.villain = arr[2];
	el.ptr = NULL;
	el.win = NULL;
	el.images = NULL;
	el.prev = set_el_2(&el);
	return (free(arr), el);
}

int	*count_elements(char **map, int length, int height)
{
	int		*arr;
	int		i;
	int		j;

	arr = malloc(sizeof(int) * 3);
	if ((arr) == NULL)
		return (NULL);
	i = 0;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	while (++i < height - 1)
	{
		j = 0;
		while (++j < length - 1)
		{
			if (map[i][j] == 'V')
				arr[2] += 1;
			if (map[i][j] == 'P')
				arr[1] = j;
			if (map[i][j] == 'P')
				arr[0] = i;
		}
	}
	return (arr);
}

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	return (-1);
}

int	fill_cell(char **map, int x, int y)
{
	int	result;

	result = 0;
	if (map[y][x] == 'E')
		return (1);
	if (map[y][x] != '1' && map[y][x] != 'T')
	{
		map[y][x] = 'T';
		result += fill_cell(map, x, y - 1);
		result += fill_cell(map, x, y + 1);
		result += fill_cell(map, x - 1, y);
		result += fill_cell(map, x + 1, y);
	}
	return (result);
}

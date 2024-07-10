/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:12:44 by sfabi             #+#    #+#             */
/*   Updated: 2024/02/02 15:33:00 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	int			length;
	int			height;
	int			consumables;
	t_el		el;

	length = 0;
	height = 0;
	consumables = 0;
	if (argc != 2)
		return (perror("Error!\ninvalid number of argument"), 1);
	map = setmap(argv[1]);
	if (check_form(map, &length, &height))
		return ((perror("Error!\nMap not rectangular"), free_map(map)));
	if (check_walls(map, length, height))
		return ((perror("Error!\nMap not surrounded"), free_map(map)));
	consumables = 0;
	if (check_el(map, length, height, &consumables))
		return ((perror("Error!\nWrong number of el"), free_map(map)));
	el = set_el(length, height, consumables, argv[1]);
	if (check_playable(map, el) || el.villain > 1)
		return ((perror("Error!\nMap not playable"), ft_free_all(&el)));
	so_long(el);
	return (0);
}

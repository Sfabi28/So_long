/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:11:52 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/29 10:29:58 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_el el)
{
	el.ptr = mlx_init();
	if (el.ptr == NULL)
		ft_malloc_error(&el);
	el.win = mlx_new_window(el.ptr, el.length * 64,
			el.height * 64 + 16, "so_long");
	if (el.win == NULL)
	{
		perror("memory allocation error");
		mlx_destroy_display(el.ptr);
		free(el.ptr);
		exit(-1);
	}
	set_images(&el);
	set_array(&el);
	locate_ghosts(&el);
	game_start(&el);
	mlx_key_hook(el.win, &key_press, &el);
	mlx_hook(el.win, 33, 1L << 5, &ft_free_all, &el);
	mlx_loop_hook(el.ptr, ft_animations, &el);
	mlx_loop(el.ptr);
}

void	game_start(t_el *el)
{
	int	i;
	int	j;

	i = 0;
	put_moves(el);
	while (i < el->height)
	{
		j = 0;
		while (j < el->length)
		{
			put_images(el, i, j);
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:37:58 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/13 13:37:59 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_exit(int keycode)
{
	if (keycode == 65307)
		exit(0);
}

void	update_collectibles(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y / TILE_SIZE][new_x / TILE_SIZE] == 2)
	{
		data->collectibles_count--;
		data->map[new_y / TILE_SIZE][new_x / TILE_SIZE] = 0;
		if (data->collectibles_count == 0)
		{
			draw_exit(data);
		}
	}
}

void	check_victory(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y / TILE_SIZE][new_x / TILE_SIZE] == 3
		&& data->collectibles_count == 0)
	{
		ft_putstr_fd("You win!\n", 1);
		mlx_string_put(data->mlx, data->win, data->map_width * TILE_SIZE / 2
			- 50, data->map_height * TILE_SIZE / 2, 0xFFFFFF, "You win!");
		mlx_loop_end(data->mlx);
	}
}

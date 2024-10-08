/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_image_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:35:51 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/13 14:35:52 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	copy_image_part(t_image_data *data)
{
	data->src_data = mlx_get_data_addr(data->src_img, &data->src_bpp,
			&data->src_size_line, &data->src_endian);
	data->dest_data = mlx_get_data_addr(data->dest_img, &data->dest_bpp,
			&data->dest_size_line, &data->dest_endian);
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			data->src_index = ((data->src_y + data->y) * data->src_size_line)
				+ ((data->src_x + data->x) * (data->src_bpp / 8));
			data->dest_index = (data->y * data->dest_size_line) + (data->x
					* (data->dest_bpp / 8));
			data->i = 0;
			while (data->i < (data->src_bpp / 8))
			{
				data->dest_data[data->dest_index
					+ data->i] = data->src_data[data->src_index + data->i];
				data->i++;
			}
			data->x++;
		}
		data->y++;
	}
}

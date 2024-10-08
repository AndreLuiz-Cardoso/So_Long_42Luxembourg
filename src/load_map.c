/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:10 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/13 13:38:11 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	**initialize_map(int initial_height)
{
	int	**map;
	int	i;

	map = malloc(sizeof(int *) * initial_height);
	if (!map)
		return (NULL);
	i = 0;
	while (i < initial_height)
	{
		map[i] = NULL;
		i++;
	}
	return (map);
}

int	*parse_line_to_map(const char *line, int width, t_data *data)
{
	int	*map_row;
	int	i;

	map_row = malloc(sizeof(int) * width);
	if (!map_row)
		return (NULL);
	i = 0;
	while (i < width)
	{
		if (line[i] == '1')
			map_row[i] = 1;
		else if (line[i] == '0')
			map_row[i] = 0;
		else if (line[i] == 'C')
		{
			map_row[i] = 2;
			data->collectibles_count++;
		}
		else if (line[i] == 'E')
			map_row[i] = 3;
		else if (line[i] == 'P')
			map_row[i] = 4;
		i++;
	}
	return (map_row);
}

void	read_map_file_recursive(t_data *data, int fd, int row)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		data->map_height = row;
		return ;
	}
	if (row == 0)
		data->map_width = ft_strlen(line) - 1;
	data->map[row] = parse_line_to_map(line, data->map_width, data);
	free(line);
	read_map_file_recursive(data, fd, row + 1);
}

void	read_map_file(t_data *data, int fd)
{
	data->collectibles_count = 0;
	read_map_file_recursive(data, fd, 0);
}

int	**load_map(const char *filename, t_data *data)
{
	int	fd;
	int	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = initialize_map(100);
	data->map = map;
	read_map_file(data, fd);
	close(fd);
	return (map);
}

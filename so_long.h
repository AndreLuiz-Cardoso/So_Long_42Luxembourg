/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:40:18 by ancardos          #+#    #+#             */
/*   Updated: 2024/08/13 13:40:19 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		**map;
	int		map_width;
	int		map_height;
	void	*img_floor;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player_up[3];
	void	*img_player_down[3];
	void	*img_player_left[3];
	void	*img_player_right[3];
	void	*img_player_current;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		frame;
	int		collectibles_count;
	int		move_count;
}			t_data;

typedef struct s_image_data
{
	void	*mlx;
	void	*src_img;
	void	*dest_img;
	int		src_x;
	int		src_y;
	int		width;
	int		height;
	char	*src_data;
	char	*dest_data;
	int		src_index;
	int		dest_index;
	int		y;
	int		x;
	int		i;
	int		src_size_line;
	int		src_endian;
	int		src_bpp;
	int		dest_bpp;
	int		dest_size_line;
	int		dest_endian;
}			t_image_data;

typedef struct s_sprite_dim
{
	int		width;
	int		height;
}			t_sprite_dim;
// gambiarra
void		funcao1(t_data *data, int i);
void		funcao2(t_data *data, int i);
void		funcao3(t_data *data, int i);
void		funcao4(t_data *data, int i);
void		funcao5(t_data *data);
void		funcao6(t_data *data);
void		funcao7(t_data *data);
void		funcao8(t_data *data);
// Inicialização
int			close_window(void *param);
void		initialize_game_window(t_data *data);
void		cleanup_images(t_data *data, int num_sprites);

// Cópia de parte da imagem
void		draw_map(t_data *data);

// Leitura do mapa
int			*parse_line_to_map(const char *line, int width, t_data *data);
void		read_map_file(t_data *data, int fd);
int			**load_map(const char *filename, t_data *data);

// Leitura de imagens
void		load_image(void **img, void *mlx, char *path, t_data *data);
void		create_images(t_data *data, int i, t_sprite_dim dim);
void		copy_sprite_part(t_image_data *img_data, int i, t_sprite_dim dim,
				int y_offset);
void		copy_sprite_images(t_data *data, t_image_data *img_data, int i,
				t_sprite_dim dim);
void		initialize_image_data(t_image_data *img_data, t_data *data,
				void *sprite_sheet, t_sprite_dim dim);
void		initialize_direction_images(t_data *data, void *sprite_sheet,
				t_sprite_dim dim);
void		initialize_images(t_data *data);
void		start_game(t_data *data);

// Eventos de teclado
int			is_wall(int x, int y, t_data *data);
void		handle_exit(int keycode);
void		update_collectibles(t_data *data, int new_x, int new_y);
void		check_victory(t_data *data, int new_x, int new_y);
void		update_position_and_image(int keycode, t_data *data, int *new_x,
				int *new_y);
int			key_event(int keycode, t_data *data);

// Funções auxiliares
void		draw_exit(t_data *data);
void		copy_image_part(t_image_data *data);
void		free_resources(t_data *data);
void		free_mlx_resources(t_data *data);
void		free_player_images(t_data *data);
void		free_images(t_data *data);
void		free_map(t_data *data);

#endif

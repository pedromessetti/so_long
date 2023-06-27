/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 08:43:44 by pedro             #+#    #+#             */
/*   Updated: 2023/06/27 12:04:29 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		x;
	int		y;
	int		endian;
}			t_data;

typedef struct s_game
{
	char	**map;
	int		map_width;
	int		map_height;

	int		moves_count;
	int		collect_count;
	int		exit_count;
	int		player_count;

	t_data	img;
	t_data	wall;
	t_data	player;
	t_data	exit;
	t_data	collect;
	t_data	floor;

	int		player_x;
	int		player_y;

	int		exit_x;
	int		exit_y;

	void	*initmlx;
	void	*winmlx;

	char	**buffer;
}			t_game;

/* --- Checker Functions --- */

int			check_fd(char *filepath);
int			check_map_size(t_game *game);
int			check_limits(t_game *game);
void		check_errors(t_game *game);
void		check_ac(int ac);

/* --- Image functions --- */

void		init_images(t_game *game);
t_data		create_image(char *path, t_game *game);
void		put_images(t_game *game);
void		put_pixel(t_game *game, int x, int y, int color);
void		load_images(t_data *image, t_game *game, int x_pos, int y_pos);
void		refresh_images_player(t_game *game, int x_pos, int y_pos,
				char flag);
void		destroy_images(t_game *game);
int			read_characters(t_game *game);

/* --- Map Functions --- */

int			save_map_line(t_game *game, char *line);
int			read_map(t_game *game, char *filepath);
void		save_coordenates(t_game *game, int y, int x, int opt);
int			control(int key, t_game *game);
void		flood_fill(char **map, int x, int y, int *counter);
int			handle_flood_fill(t_game *game);
void		map_error(t_game *game);

/* --- Control Functions --- */

void		move_w(t_game *game);
void		move_a(t_game *game);
void		move_s(t_game *game);
void		move_d(t_game *game);
int			control(int key, t_game *game);
void		exit_game(t_game *game);

#endif

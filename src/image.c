/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:21:18 by pedro             #+#    #+#             */
/*   Updated: 2023/06/27 20:56:21 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	create_image(char *path, t_game *game)
{
	t_data	img;

	img.ptr = mlx_xpm_file_to_image(game->initmlx, path, (int *)&img.x,
			(int *)&img.y);
	img.addr = mlx_get_data_addr(img.ptr, &(img.bpp), &(img.line_len),
			&(img.endian));
	return (img);
}

void	init_images(t_game *game)
{
	game->img.ptr = mlx_new_image(game->initmlx, game->map_width * 64,
			game->map_height * 64);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &(game->img.bpp),
			&(game->img.line_len), &(game->img.endian));
	game->floor = create_image("textures/grama.xpm", game);
	game->wall = create_image("textures/wall.xpm", game);
	game->player = create_image("textures/fla.xpm", game);
	game->exit = create_image("textures/exit.xpm", game);
	game->collect = create_image("textures/liberta.xpm", game);
	put_images(game);
}

void	put_images(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			choose_image(game, y, x);
	}
}

void	choose_image(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'P'
		|| game->map[y][x] == 'C' || game->map[y][x] == 'E')
		mlx_put_image_to_window(game->initmlx, game->winmlx, game->floor.ptr, x
			* 64, y * 64);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->initmlx, game->winmlx, game->player.ptr, x
			* 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->initmlx, game->winmlx, game->collect.ptr,
			x * 64, y * 64);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->initmlx, game->winmlx, game->wall.ptr, x
			* 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->initmlx, game->winmlx, game->exit.ptr, x
			* 64, y * 64);
}

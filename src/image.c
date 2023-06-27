/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:21:18 by pedro             #+#    #+#             */
/*   Updated: 2023/06/26 23:23:14 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_len) + (x * (game->img.bpp / 8));
	*(unsigned int *)dst = color;
}

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

void	load_images(t_data *image, t_game *game, int x_pos, int y_pos)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < image->y)
	{
		x = 0;
		while (x < image->x)
		{
			color = *(unsigned int *)(image->addr + y * image->line_len + x
					* (image->bpp / 8));
			if (color != 4278190080)
				put_pixel(game, x_pos * 64 + x, y_pos * 64 + y, color);
			x++;
		}
		y++;
	}
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
		{
			if (game->map[y][x] == '0' || game->map[y][x] == 'P'
				|| game->map[y][x] == 'C' || game->map[y][x] == 'E')
				load_images(&game->floor, game, x, y);
			if (game->map[y][x] == 'P')
				load_images(&game->player, game, x, y);
			else if (game->map[y][x] == 'C')
				load_images(&game->collect, game, x, y);
			else if (game->map[y][x] == '1')
				load_images(&game->wall, game, x, y);
			else if (game->map[y][x] == 'E')
				load_images(&game->exit, game, x, y);
		}
	}
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.ptr, 0, 0);
}

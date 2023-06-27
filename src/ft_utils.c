/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:42:44 by pedro             #+#    #+#             */
/*   Updated: 2023/06/27 21:01:13 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh_images_player(t_game *game, int x, int y, char flag)
{
	mlx_clear_window(game->initmlx, game->winmlx);
	put_images(game);
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->floor.ptr, x
		* 64, y * 64);
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->exit.ptr,
		game->exit_x * 64, game->exit_y * 64);
	if (flag == 'w')
		container(game, x, y - 1);
	else if (flag == 'a')
		container(game, x - 1, y);
	else if (flag == 's')
		container(game, x, y + 1);
	else if (flag == 'd')
		container(game, x + 1, y);
}

void	container(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->floor.ptr, x
		* 64, y * 64);
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->player.ptr, x
		* 64, y * 64);
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->initmlx, game->img.ptr);
	mlx_destroy_image(game->initmlx, game->wall.ptr);
	mlx_destroy_image(game->initmlx, game->player.ptr);
	mlx_destroy_image(game->initmlx, game->exit.ptr);
	mlx_destroy_image(game->initmlx, game->collect.ptr);
	mlx_destroy_image(game->initmlx, game->floor.ptr);
}

void	exit_game(t_game *game)
{
	free_matrix(game->map);
	destroy_images(game);
	if (game->winmlx)
		mlx_destroy_window(game->initmlx, game->winmlx);
	mlx_destroy_display(game->initmlx);
	free(game->initmlx);
	ft_printf("\nExit Fla Game\n");
	exit(0);
}

void	save_coordenates(t_game *game, int y, int x, int opt)
{
	if (opt)
	{
		game->player_x = x;
		game->player_y = y;
		game->player_count++;
		return ;
	}
	game->exit_x = x;
	game->exit_y = y;
	game->exit_count++;
}

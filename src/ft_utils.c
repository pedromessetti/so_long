/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:42:44 by pedro             #+#    #+#             */
/*   Updated: 2023/06/26 23:31:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh_images_player(t_game *game, int x_pos, int y_pos, char flag)
{
	load_images(&game->floor, game, x_pos, y_pos);
	load_images(&game->exit, game, game->exit_x, game->exit_y);
	if (game->collect_count == 0)
		load_images(&game->exit, game, game->exit_x, game->exit_y);
	if (flag == 'w')
	{
		load_images(&game->floor, game, x_pos, y_pos - 1);
		load_images(&game->player, game, x_pos, y_pos - 1);
	}
	else if (flag == 'a')
	{
		load_images(&game->floor, game, x_pos - 1, y_pos);
		load_images(&game->player, game, x_pos - 1, y_pos);
	}
	else if (flag == 's')
	{
		load_images(&game->floor, game, x_pos, y_pos + 1);
		load_images(&game->player, game, x_pos, y_pos + 1);
	}
	else if (flag == 'd')
	{
		load_images(&game->floor, game, x_pos + 1, y_pos);
		load_images(&game->player, game, x_pos + 1, y_pos);
	}
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.ptr, 0, 0);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:42:44 by pedro             #+#    #+#             */
/*   Updated: 2023/06/28 09:05:36 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, int *counter)
{
	if (map[y][x] == 'C' || map[y][x] == 'E')
		*counter += 1;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = 'F';
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
		flood_fill(map, x + 1, y, counter);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
		flood_fill(map, x - 1, y, counter);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F')
		flood_fill(map, x, y + 1, counter);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
		flood_fill(map, x, y - 1, counter);
}

int	handle_flood_fill(t_game *game)
{
	int		counter;
	char	**map_tmp;
	int		i;

	map_tmp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_tmp)
		return (0);
	counter = 0;
	i = -1;
	while (game->map[++i])
		map_tmp[i] = ft_strdup(game->map[i]);
	map_tmp[i] = NULL;
	flood_fill(map_tmp, game->player_x, game->player_y, &counter);
	free_matrix(map_tmp);
	return (counter == (game->exit_count + game->collect_count));
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

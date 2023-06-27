/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:43:36 by pedro             #+#    #+#             */
/*   Updated: 2023/06/27 13:13:16 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, int *counter)
{
	if (map[y][x] == 'C' || map[y][x] == 'E')
		*counter += 1;
	if (map[y][x] == 'E')
		map[y][x] = '1';
	else
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

int	read_characters(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->collect_count++;
			else if (game->map[y][x] == 'E')
				save_coordenates(game, y, x, 0);
			else if (game->map[y][x] == 'P')
				save_coordenates(game, y, x, 1);
			else if (game->map[y][x] != '1' && game->map[y][x] != '0')
				return (0);
		}
	}
	return (1);
}

void	map_error(t_game *game)
{
	write(2, "Error: Map not supported\n", 25);
	free_matrix(game->map);
	exit(EXIT_FAILURE);
}

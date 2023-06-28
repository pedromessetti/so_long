/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:41:16 by pedro             #+#    #+#             */
/*   Updated: 2023/06/28 09:05:11 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	save_map_line(t_game *game, char *line)
{
	char	**temp_map;
	int		i;

	if (!line)
		return (0);
	i = -1;
	game->map_height += 1;
	temp_map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!temp_map)
		return (0);
	temp_map[game->map_height] = NULL;
	while (++i < game->map_height - 1)
		temp_map[i] = game->map[i];
	temp_map[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp_map;
	return (1);
}

int	read_map(t_game *game, char *filepath)
{
	int		fd;
	char	*line;

	fd = check_fd(filepath);
	while (1)
	{
		line = get_next_line(fd);
		if (!save_map_line(game, line))
			break ;
	}
	close(fd);
	if (game->map)
		game->map_width = ft_strlen(game->map[0]) - 1;
	return (1);
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

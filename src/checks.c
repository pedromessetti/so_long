/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:56:36 by pedro             #+#    #+#             */
/*   Updated: 2023/06/26 23:07:46 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ac(int ac)
{
	if (ac == 2)
		return ;
	else if (ac > 2)
	{
		write(2, "Error: Too many aguments\n", 25);
		exit(EXIT_FAILURE);
	}
	else
	{
		write(2, "Error: Too few aguments\n", 25);
		exit(EXIT_FAILURE);
	}
}

int	check_fd(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: %s: %s\n", filepath, strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (!strrchr(filepath, '.') || ft_strncmp(ft_strrchr(filepath, '.'),
			".ber\0", 5) != 0)
	{
		write(2, "Error: Map not supported\n", 25);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	check_limits(t_game *game)
{
	int	i;
	int	lp;

	lp = game->map_height - 1;
	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] == '1' && game->map[lp][i] == '1')
			i++;
		else
			return (0);
	}
	lp = game->map_width - 1;
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] == '1' && game->map[i][lp] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_map_size(t_game *game)
{
	int	i;
	int	j;
	int	line_size;

	i = 0;
	while (game->map[++i])
	{
		j = 0;
		line_size = 0;
		while (game->map[i][j])
			if (game->map[i][j++] != '\n')
				line_size++;
		if (line_size != game->map_width)
			return (0);
	}
	return (1);
}

void	check_errors(t_game *game)
{
	if (!game->map)
		map_error(game);
	else if (!check_map_size(game) || (game->map_height == game->map_width))
		map_error(game);
	else if (!read_characters(game))
		map_error(game);
	else if (!check_limits(game))
		map_error(game);
	else if (game->collect_count < 1)
		map_error(game);
	else if (game->exit_count != 1)
		map_error(game);
	else if (game->player_count != 1)
		map_error(game);
	else if (!handle_flood_fill(game))
		map_error(game);
}
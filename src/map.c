/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:41:16 by pedro             #+#    #+#             */
/*   Updated: 2023/06/25 20:31:46 by pedro            ###   ########.fr       */
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

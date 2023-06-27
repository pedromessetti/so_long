/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:41:59 by pedro             #+#    #+#             */
/*   Updated: 2023/06/27 11:01:22 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] == '1' || (game->map[y - 1][x] == 'E'
			&& game->collect_count != 0))
		return ;
	if (game->map[y - 1][x] == 'E' && game->collect_count == 0)
		exit_game(game);
	else if (game->map[y - 1][x] == 'C')
		game->collect_count--;
	refresh_images_player(game, x, y, 'w');
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'P';
	game->player_y--;
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
}

void	move_s(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] == '1' || (game->map[y + 1][x] == 'E'
			&& game->collect_count != 0))
		return ;
	if (game->map[y + 1][x] == 'E' && game->collect_count == 0)
		exit_game(game);
	else if (game->map[y + 1][x] == 'C')
		game->collect_count--;
	refresh_images_player(game, x, y, 's');
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'P';
	game->player_y++;
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
}

void	move_a(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] == '1' || (game->map[y][x - 1] == 'E'
			&& game->collect_count != 0))
		return ;
	if (game->map[y][x - 1] == 'E' && game->collect_count == 0)
		exit_game(game);
	else if (game->map[y][x - 1] == 'C')
		game->collect_count--;
	refresh_images_player(game, x, y, 'a');
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'P';
	game->player_x--;
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
}

void	move_d(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] == '1' || (game->map[y][x + 1] == 'E'
			&& game->collect_count != 0))
		return ;
	if (game->map[y][x + 1] == 'E' && game->collect_count == 0)
		exit_game(game);
	else if (game->map[y][x + 1] == 'C')
		game->collect_count--;
	refresh_images_player(game, x, y, 'd');
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'P';
	game->player_x++;
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
}

int	control(int key, t_game *game)
{
	if (key == 65307)
		exit_game(game);
	if (key == 119)
		move_w(game);
	if (key == 97)
		move_a(game);
	if (key == 115)
		move_s(game);
	if (key == 100)
		move_d(game);
	return (1);
}

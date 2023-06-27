/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:36:55 by pedro             #+#    #+#             */
/*   Updated: 2023/06/26 22:36:07 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	fla_game;

	check_ac(ac);
	read_map(&fla_game, av[1]);
	check_errors(&fla_game);
	fla_game.initmlx = mlx_init();
	fla_game.winmlx = mlx_new_window(fla_game.initmlx, (fla_game.map_width
			* 64), (fla_game.map_height * 64), "FLA GAME");
	init_images(&fla_game);
	mlx_key_hook(fla_game.winmlx, &control, &fla_game);
	mlx_hook(fla_game.winmlx, 17, 0L, (void *)exit_game, &fla_game);
	mlx_loop(fla_game.initmlx);
	return (0);
}

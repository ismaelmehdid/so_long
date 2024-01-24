/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:45 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/24 22:48:31 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	map = errors_handling(argc, argv);
	if (!map)
	{
		write(2, "Either bad arguments, or your map isn't correct\n", 48);
		exit(EXIT_FAILURE);
	}
	game_init(&game, map);
	if (game.mlx_connection == NULL || game.mlx_window == NULL)
	{
		free_double_array(map);
		exit(EXIT_FAILURE);
	}
	game_init_images(&game);
	game_render(&game);
	mlx_loop(game.mlx_connection);
	return (0);
}

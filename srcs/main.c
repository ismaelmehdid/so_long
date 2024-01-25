/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:45 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/25 22:18:17 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	hook_event_listener(struct s_game *game)
{
	if (game->map[game->player_pos_y][game->player_pos_x] == 'E'
	&& game->nb_coins == 0)
	{
		program_exit(game);
		printf("nb moves : %d \n\n", game->nb_moves);
		exit(EXIT_SUCCESS);
	}
	mlx_string_put(game->mlx_connection, game->mlx_window,
		(game->window_width / 2), (game->window_height - 10), 0xf12215,
		ft_itoa(game->nb_moves));
	return (0);
}

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
	mlx_loop_hook(game.mlx_connection, hook_event_listener, &game);
	mlx_loop(game.mlx_connection);
	return (0);
}

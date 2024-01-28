/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:45 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/28 01:33:54 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_success(struct s_game *game)
{
	ft_printf(" _____ _   _ _____  _____  _____ _____ _____ \n");
	ft_printf("/  ___| | | /  __ \\/  __ \\|  ___/  ___/  ___|\n");
	ft_printf("\\ `--.| | | | /  \\/| /  \\/| |__ \\ `--.\\ `--. \n");
	ft_printf(" `--. \\ | | | |    | |    |  __| `--. \\`--. \\\n");
	ft_printf("/\\__/ / |_| | \\__/\\| \\__/\\| |___/\\__/ /\\__/ /\n");
	ft_printf("\\____/ \\___/ \\____/ \\____/\\____/\\____/\\____/ \n");
	ft_printf("Your score : %d moves\n", game->nb_moves);
}

int	hook_event_listener(struct s_game *game)
{
	if (game->map[game->player_pos_y][game->player_pos_x] == 'E'
			&& game->nb_coins == 0)
	{
		display_success(game);
		program_exit(game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	map = errors_handling(argc, argv);
	if (!map)
	{
		write(2, "Error\n", 7);
		write(2, "Either bad arguments or your map isn't correct\n", 48);
		exit(EXIT_FAILURE);
	}
	game_init(&game, map);
	if (game.mlx_connection == NULL || game.mlx_window == NULL)
	{
		if (game.mlx_connection)
			free(game.mlx_connection);
		free_double_array(map);
		exit(EXIT_FAILURE);
	}
	game_render(&game);
	mlx_loop_hook(game.mlx_connection, hook_event_listener, &game);
	mlx_loop(game.mlx_connection);
	return (0);
}

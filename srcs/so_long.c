/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:45 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/29 14:47:23 by ismaelmehdi      ###   ########.fr       */
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
	ft_printf("Your score : %d moves\n", game->player->nb_moves);
}

int	hook_event_listener(struct s_game *game)
{
	if (game->map[game->player->pos_y][game->player->pos_x] == 'E'
			&& game->player->nb_coins == 0)
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
	if (!game_init(&game, map))
		program_exit(&game);
	game_render(&game);
	mlx_loop_hook(game.mlx->mlx_con, hook_event_listener, &game);
	mlx_loop(game.mlx->mlx_con);
	return (0);
}

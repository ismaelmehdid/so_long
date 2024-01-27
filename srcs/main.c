/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:45 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/27 02:33:34 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_success(struct s_game *game)
{
	printf(" _____ _   _ _____  _____  _____ _____ _____ \n");
    printf("/  ___| | | /  __ \\/  __ \\|  ___/  ___/  ___|\n");
    printf("\\ `--.| | | | /  \\/| /  \\/| |__ \\ `--.\\ `--. \n");
    printf(" `--. \\ | | | |    | |    |  __| `--. \\`--. \\\n");
    printf("/\\__/ / |_| | \\__/\\| \\__/\\| |___/\\__/ /\\__/ /\n");
    printf("\\____/ \\___/ \\____/ \\____/\\____/\\____/\\____/ \n");
	printf("Your score : %d moves\n", game->nb_moves);
}

void	render_nb_moves(struct s_game *game)
{
	char	*str;

	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
		game->wall_image, 0, 0);
	str = ft_itoa(game->nb_moves);
	mlx_string_put(game->mlx_connection, game->mlx_window,
			game->width_image / 2 - 3, game->height_image / 2 - 3, -1, str);
	free(str);
}

int	hook_event_listener(struct s_game *game)
{
	if (game->map[game->player_pos_y][game->player_pos_x] == 'E'
	&& game->nb_coins == 0)
	{
		display_success(game);
		program_exit(game);
	}
	if (game->map[game->player_pos_y][game->player_pos_x] == 'A')
		program_exit(game);
	render_nb_moves(game);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;
	t_enemy_images	enemy;

	map = errors_handling(argc, argv);
	if (!map)
	{
		write(2, "Either bad arguments, or your map isn't correct\n", 48);
		exit(EXIT_FAILURE);
	}
	game_init(&game, map, &enemy);
	if (game.mlx_connection == NULL || game.mlx_window == NULL)
	{
		if (game.mlx_connection)
			free(game.mlx_connection);
		free_double_array(map);
		exit(EXIT_FAILURE);
	}
	game_init_images(&game);
	game_init_images_player(&game);
	game_init_images_enemy(&game);
	game_render(&game);
	mlx_loop_hook(game.mlx_connection, hook_event_listener, &game);
	mlx_loop(game.mlx_connection);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:45 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/29 20:17:42 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_nb_moves(struct s_game *game)
{
	static char	*nb_moves;
	static int	nbmoves;

	nb_moves = ft_itoa(game->player->nb_moves);
	if (nbmoves == 0 || ft_atoi(nb_moves) != nbmoves)
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->props->wall_image, 0, 0);
	mlx_string_put(game->mlx->mlx_con, game->mlx->mlx_window,
		29, 27, 0xFFFFFF,
		nb_moves);
	nbmoves = ft_atoi(nb_moves);
	free (nb_moves);
}

int	game_render_loop(struct s_game *game)
{
	display_nb_moves(game);
	if (game->player->pos_y == game->props->exit_pos_y
		&& game->player->pos_x == game->props->exit_pos_x
		&& game->player->nb_coins == 0)
	{
		display_success(game);
		program_exit(game);
	}
	get_player_pos(game);
	game_render(game);
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
	mlx_loop_hook(game.mlx->mlx_con, game_render_loop, &game);
	mlx_loop(game.mlx->mlx_con);
	return (0);
}

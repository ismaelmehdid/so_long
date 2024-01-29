/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:14:11 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/29 20:24:37 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	game_init_others(t_game *game)
{
	get_player_pos(game);
	get_nb_coins(game);
	get_exit_pos(game);
	game->player->move_done = 'd';
	game->player->nb_moves = 0;
	game->mlx->width_image = 64;
	game->mlx->height_image = 64;
	game->mlx->window_width =
		game->mlx->width_image * ft_strlen(game->map[0]);
	game->mlx->window_height =
		game->mlx->height_image * double_array_size(game->map);
}

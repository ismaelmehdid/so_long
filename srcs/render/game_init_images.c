/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:28:42 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/26 20:55:21 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_init_images(struct s_game *game)
{
	game->wall_image = mlx_xpm_file_to_image(game->mlx_connection,
			"./srcs/sprites/wall.xpm", &(game->width_image),
			&(game->height_image));
	if (game->wall_image == NULL)
		return ;
	game->ground_image = mlx_xpm_file_to_image(game->mlx_connection,
			"./srcs/sprites/ground.xpm", &(game->width_image),
			&(game->height_image));
	if (game->ground_image == NULL)
		return ;
	game->exit_image = mlx_xpm_file_to_image(game->mlx_connection,
			"./srcs/sprites/exit.xpm", &(game->width_image),
			&(game->height_image));
	if (game->exit_image == NULL)
		return ;
	game->coin_image = mlx_xpm_file_to_image(game->mlx_connection,
			"./srcs/sprites/coin.xpm", &(game->width_image),
			&(game->height_image));
	if (game->coin_image == NULL)
		return ;
}

void	game_init_images_player(struct s_game *game)
{
	game->player_back_image = mlx_xpm_file_to_image(game->mlx_connection,
			"./srcs/sprites/back.xpm", &(game->width_image),
			&(game->height_image));
	if (game->player_back_image == NULL)
		return ;
	game->player_front_image = mlx_xpm_file_to_image(game->mlx_connection,
			"./srcs/sprites/front.xpm", &(game->width_image),
			&(game->height_image));
	if (game->player_front_image == NULL)
		return ;
	game->player_right_image = mlx_xpm_file_to_image(game->mlx_connection,
			"./srcs/sprites/right.xpm", &(game->width_image),
			&(game->height_image));
	if (game->player_right_image == NULL)
		return ;
	game->player_left_image = mlx_xpm_file_to_image(game->mlx_connection,
			"./srcs/sprites/left.xpm", &(game->width_image),
			&(game->height_image));
	if (game->player_left_image == NULL)
		return ;
}
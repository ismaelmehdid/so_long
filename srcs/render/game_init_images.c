/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:28:42 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/28 03:52:23 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	game_init_images(struct s_game *game)
{
	game->props->wall_image = mlx_xpm_file_to_image(
			game->mlx->mlx_con,
			"./srcs/sprites/wall.xpm", &(game->mlx->width_image),
			&(game->mlx->height_image));
	if (game->props->wall_image == NULL)
		return (0);
	game->props->ground_image = mlx_xpm_file_to_image(
			game->mlx->mlx_con,
			"./srcs/sprites/ground.xpm", &(game->mlx->width_image),
			&(game->mlx->height_image));
	if (game->props->ground_image == NULL)
		return (0);
	game->props->exit_image = mlx_xpm_file_to_image(
			game->mlx->mlx_con,
			"./srcs/sprites/exit.xpm", &(game->mlx->width_image),
			&(game->mlx->height_image));
	if (game->props->exit_image == NULL)
		return (0);
	game->props->coin_image = mlx_xpm_file_to_image(
			game->mlx->mlx_con,
			"./srcs/sprites/coin.xpm", &(game->mlx->width_image),
			&(game->mlx->height_image));
	if (game->props->coin_image == NULL)
		return (0);
	return (1);
}

int	game_init_images_player(struct s_game *game)
{
	game->player->back_image = mlx_xpm_file_to_image(
			game->mlx->mlx_con,
			"./srcs/sprites/back.xpm", &(game->mlx->width_image),
			&(game->mlx->height_image));
	if (game->player->back_image == NULL)
		return (0);
	game->player->front_image = mlx_xpm_file_to_image(
			game->mlx->mlx_con,
			"./srcs/sprites/front.xpm", &(game->mlx->width_image),
			&(game->mlx->height_image));
	if (game->player->front_image == NULL)
		return (0);
	game->player->right_image = mlx_xpm_file_to_image(
			game->mlx->mlx_con,
			"./srcs/sprites/right.xpm", &(game->mlx->width_image),
			&(game->mlx->height_image));
	if (game->player->right_image == NULL)
		return (0);
	game->player->left_image = mlx_xpm_file_to_image(
			game->mlx->mlx_con,
			"./srcs/sprites/left.xpm", &(game->mlx->width_image),
			&(game->mlx->height_image));
	if (game->player->left_image == NULL)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:16:35 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/24 22:53:15 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_init(struct s_game *game, char **map)
{
	game->map = map;
	game->width_image = 64;
	game->height_image = 64;
	game->window_width = game->width_image * ft_strlen(map[0]);
	game->window_height = game->height_image * double_array_size(map);
	game->mlx_connection = mlx_init();
	if (game->mlx_connection == NULL)
		return ;
	game->mlx_window = mlx_new_window(game->mlx_connection,
			game->window_width, game->window_height, "Incredible game");
	if (game->mlx_window == NULL)
		return ;
}

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
	game->player_image = mlx_xpm_file_to_image(game->mlx_connection,
			"./srcs/sprites/player.xpm", &(game->width_image),
			&(game->height_image));
	if (game->player_image == NULL)
		return ;
	game->coin_image = mlx_xpm_file_to_image(game->mlx_connection,
			"./srcs/sprites/coin.xpm", &(game->width_image),
			&(game->height_image));
	if (game->coin_image == NULL)
		return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:57:06 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/25 22:20:27 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_up(struct s_game *game)
{
	if (game->map[game->player_pos_y - 1][game->player_pos_x] == '1')
		return ;
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
		game->player_image, (game->player_pos_x) * game->width_image,
		(game->player_pos_y - 1) * game->height_image);
	if (game->map[game->player_pos_y][game->player_pos_x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->exit_image, (game->player_pos_x) * game->width_image,
			(game->player_pos_y) * game->height_image);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->ground_image, (game->player_pos_x) * game->width_image,
			(game->player_pos_y) * game->height_image);
	}
	if (game->map[game->player_pos_y - 1][game->player_pos_x] == 'C')
	{
		game->map[game->player_pos_y - 1][game->player_pos_x] = '0';
		game->nb_coins--;
	}
	game->player_pos_y -= 1;
	game->nb_moves += 1;
}

void	render_down(struct s_game *game)
{
	if (game->map[game->player_pos_y + 1][game->player_pos_x] == '1')
		return ;
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
		game->player_image, (game->player_pos_x) * game->width_image,
		(game->player_pos_y + 1) * game->height_image);
	if (game->map[game->player_pos_y][game->player_pos_x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->exit_image, (game->player_pos_x) * game->width_image,
			(game->player_pos_y) * game->height_image);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->ground_image, (game->player_pos_x) * game->width_image,
			(game->player_pos_y) * game->height_image);
	}
	if (game->map[game->player_pos_y + 1][game->player_pos_x] == 'C')
	{
		game->map[game->player_pos_y + 1][game->player_pos_x] = '0';
		game->nb_coins--;
	}
	game->player_pos_y += 1;
	game->nb_moves += 1;
}

void	render_left(struct s_game *game)
{
	if (game->map[game->player_pos_y][game->player_pos_x - 1] == '1')
		return ;
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
		game->player_image, (game->player_pos_x - 1) * game->width_image,
		(game->player_pos_y) * game->height_image);
	if (game->map[game->player_pos_y][game->player_pos_x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->exit_image, (game->player_pos_x) * game->width_image,
			(game->player_pos_y) * game->height_image);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->ground_image, (game->player_pos_x) * game->width_image,
			(game->player_pos_y) * game->height_image);
	}
	if (game->map[game->player_pos_y][game->player_pos_x - 1] == 'C')
	{
		game->map[game->player_pos_y][game->player_pos_x - 1] = '0';
		game->nb_coins--;
	}
	game->player_pos_x -= 1;
	game->nb_moves += 1;
}

void	render_right(struct s_game *game)
{
	if (game->map[game->player_pos_y][game->player_pos_x + 1] == '1')
		return ;
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
		game->player_image, (game->player_pos_x + 1) * game->width_image,
		(game->player_pos_y) * game->height_image);
	if (game->map[game->player_pos_y][game->player_pos_x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->exit_image, (game->player_pos_x) * game->width_image,
			(game->player_pos_y) * game->height_image);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->ground_image, (game->player_pos_x) * game->width_image,
			(game->player_pos_y) * game->height_image);
	}
	if (game->map[game->player_pos_y][game->player_pos_x + 1] == 'C')
	{
		game->map[game->player_pos_y][game->player_pos_x + 1] = '0';
		game->nb_coins--;
	}
	game->player_pos_x += 1;
	game->nb_moves += 1;
}

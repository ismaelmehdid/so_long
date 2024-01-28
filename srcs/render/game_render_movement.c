/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:57:06 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/28 03:56:11 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_up(struct s_game *game)
{
	if (game->map[game->player->pos_y - 1][game->player->pos_x] == '1')
		return ;
	mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
		game->player->back_image,
		(game->player->pos_x) * game->mlx->width_image,
		(game->player->pos_y - 1) * game->mlx->height_image);
	if (game->map[game->player->pos_y][game->player->pos_x] == 'E')
		mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
			game->props->exit_image,
			(game->player->pos_x) * game->mlx->width_image,
			(game->player->pos_y) * game->mlx->height_image);
	else
		mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
			game->props->ground_image,
			(game->player->pos_x) * game->mlx->width_image,
			(game->player->pos_y) * game->mlx->height_image);
	if (game->map[game->player->pos_y - 1][game->player->pos_x] == 'C')
	{
		game->map[game->player->pos_y - 1][game->player->pos_x] = '0';
		game->player->nb_coins--;
	}
	game->player->pos_y -= 1;
	game->player->nb_moves += 1;
	ft_printf("You moved %d times\n", game->player->nb_moves);
}

void	render_down(struct s_game *game)
{
	if (game->map[game->player->pos_y + 1][game->player->pos_x] == '1')
		return ;
	mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
		game->player->front_image,
		(game->player->pos_x) * game->mlx->width_image,
		(game->player->pos_y + 1) * game->mlx->height_image);
	if (game->map[game->player->pos_y][game->player->pos_x] == 'E')
		mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
			game->props->exit_image,
			(game->player->pos_x) * game->mlx->width_image,
			(game->player->pos_y) * game->mlx->height_image);
	else
		mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
			game->props->ground_image,
			(game->player->pos_x) * game->mlx->width_image,
			(game->player->pos_y) * game->mlx->height_image);
	if (game->map[game->player->pos_y + 1][game->player->pos_x] == 'C')
	{
		game->map[game->player->pos_y + 1][game->player->pos_x] = '0';
		game->player->nb_coins--;
	}
	game->player->pos_y += 1;
	game->player->nb_moves += 1;
	ft_printf("You moved %d times\n", game->player->nb_moves);
}

void	render_left(struct s_game *game)
{
	if (game->map[game->player->pos_y][game->player->pos_x - 1] == '1')
		return ;
	mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
		game->player->left_image,
		(game->player->pos_x - 1) * game->mlx->width_image,
		(game->player->pos_y) * game->mlx->height_image);
	if (game->map[game->player->pos_y][game->player->pos_x] == 'E')
		mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
			game->props->exit_image,
			(game->player->pos_x) * game->mlx->width_image,
			(game->player->pos_y) * game->mlx->height_image);
	else
		mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
			game->props->ground_image,
			(game->player->pos_x) * game->mlx->width_image,
			(game->player->pos_y) * game->mlx->height_image);
	if (game->map[game->player->pos_y][game->player->pos_x - 1] == 'C')
	{
		game->map[game->player->pos_y][game->player->pos_x - 1] = '0';
		game->player->nb_coins--;
	}
	game->player->pos_x -= 1;
	game->player->nb_moves += 1;
	ft_printf("You moved %d times\n", game->player->nb_moves);
}

void	render_right(struct s_game *game)
{
	if (game->map[game->player->pos_y][game->player->pos_x + 1] == '1')
		return ;
	mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
		game->player->right_image,
		(game->player->pos_x + 1) * game->mlx->width_image,
		(game->player->pos_y) * game->mlx->height_image);
	if (game->map[game->player->pos_y][game->player->pos_x] == 'E')
		mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
			game->props->exit_image,
			(game->player->pos_x) * game->mlx->width_image,
			(game->player->pos_y) * game->mlx->height_image);
	else
		mlx_put_image_to_window(game->mlx->mlx_con, game->mlx->mlx_window,
			game->props->ground_image,
			(game->player->pos_x) * game->mlx->width_image,
			(game->player->pos_y) * game->mlx->height_image);
	if (game->map[game->player->pos_y][game->player->pos_x + 1] == 'C')
	{
		game->map[game->player->pos_y][game->player->pos_x + 1] = '0';
		game->player->nb_coins--;
	}
	game->player->pos_x += 1;
	game->player->nb_moves += 1;
	ft_printf("You moved %d times\n", game->player->nb_moves);
}

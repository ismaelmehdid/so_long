/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:07:50 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/29 20:29:49 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	game_render(struct s_game *game)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	x = 64;
	y = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			game_render_props(game, game->map[j][i], x, y);
			x += game->mlx->width_image;
			i++;
		}
		i = 0;
		x = 0;
		y += game->mlx->height_image;
		j++;
	}
	game_render_player(game);
	game_render_enemy(game);
}

void	game_render_props(struct s_game *game, char prop, int x, int y)
{
	if (x == game->player->pos_x && y == game->player->pos_y)
		return ;
	if (prop == '1')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->props->wall_image, x, y);
	else if (prop == '0')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->props->ground_image, x, y);
	else if (prop == 'E')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->props->exit_image, x, y);
	else if (prop == 'C')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->props->coin_image, x, y);
}

void	game_render_player(struct s_game *game)
{
	if (game->player->move_done == 'd')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->player->front_image,
			game->player->pos_x * game->mlx->width_image,
			game->player->pos_y * game->mlx->height_image);
	if (game->player->move_done == 'u')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->player->back_image,
			game->player->pos_x * game->mlx->width_image,
			game->player->pos_y * game->mlx->height_image);
	if (game->player->move_done == 'l')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->player->left_image,
			game->player->pos_x * game->mlx->width_image,
			game->player->pos_y * game->mlx->height_image);
	if (game->player->move_done == 'r')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->player->right_image,
			game->player->pos_x * game->mlx->width_image,
			game->player->pos_y * game->mlx->height_image);
}

void	game_render_enemy(struct s_game *game)
{
	static int		image_index = 0;
	static clock_t	last_update = 0;
	clock_t			current_time;

	current_time = clock();
	if ((double)(current_time - last_update) / CLOCKS_PER_SEC >= 0.3
	|| last_update == 0)
	{
		image_index = (image_index + 1) % 4;
		if (image_index == 0)
			game->props->current_image = game->props->enemy_image_1;
		else if (image_index == 1)
			game->props->current_image = game->props->enemy_image_2;
		else if (image_index == 2)
			game->props->current_image = game->props->enemy_image_3;
		else if (image_index == 3)
			game->props->current_image = game->props->enemy_image_4;
		game_render_current_enemy(game);
		last_update = current_time;
	}
}

void	game_render_current_enemy(struct s_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'A')
				mlx_put_image_to_window(game->mlx->mlx_con,
					game->mlx->mlx_window,
					game->props->current_image,
					i * game->mlx->width_image,
					j * game->mlx->height_image);
			i++;
		}
		i = 0;
		j++;
	}
}

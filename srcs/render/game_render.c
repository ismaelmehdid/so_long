/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:07:50 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/28 03:52:22 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_render(struct s_game *game)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			put_image(game, game->map[j][i], x, y);
			x += game->mlx->width_image;
			i++;
		}
		i = 0;
		x = 0;
		y += game->mlx->height_image;
		j++;
	}
}

void	put_image(struct s_game *game, char prop, int x, int y)
{
	if (prop == '1')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->props->wall_image, x, y);
	else if (prop == '0')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->props->ground_image, x, y);
	else if (prop == 'P')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->player->front_image, x, y);
	else if (prop == 'E')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->props->exit_image, x, y);
	else if (prop == 'C')
		mlx_put_image_to_window(game->mlx->mlx_con,
			game->mlx->mlx_window,
			game->props->coin_image, x, y);
}

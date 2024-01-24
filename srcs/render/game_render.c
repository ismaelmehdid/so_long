/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:07:50 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/24 22:49:18 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_render(struct s_game *game)
{
	char	**map;
	int		i;
	int		j;
	int		x;
	int		y;

	map = game->map;
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			put_image(game, map[j][i], x, y);
			x += game->width_image;
			i++;
		}
		i = 0;
		x = 0;
		y += game->height_image;
		j++;
	}
}

void	put_image(struct s_game *game, char prop, int x, int y)
{
	if (prop == '1')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->wall_image, x, y);
	else if (prop == '0')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->ground_image, x, y);
	else if (prop == 'P')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->player_image, x, y);
	else if (prop == 'E')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->exit_image, x, y);
	else if (prop == 'C')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->coin_image, x, y);
}

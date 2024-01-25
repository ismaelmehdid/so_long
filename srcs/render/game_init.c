/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:16:35 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/25 22:19:22 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_nb_coins(struct s_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->nb_coins++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	get_player_pos(struct s_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->player_pos_x = x;
				game->player_pos_y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		exit(EXIT_FAILURE);
	else if (keysym == XK_z)
		render_up(game);
	else if (keysym == XK_s)
		render_down(game);
	else if (keysym == XK_q)
		render_left(game);
	else if (keysym == XK_d)
		render_right(game);
	return (0);
}

void	game_init(struct s_game *game, char **map)
{
	game->map = map;
	get_player_pos(game);
	get_nb_coins(game);
	game->nb_moves = 0;
	game->width_image = 64;
	game->height_image = 64;
	game->window_width = game->width_image * ft_strlen(map[0]);
	game->window_height = game->height_image * double_array_size(map) + 30;
	game->mlx_connection = mlx_init();
	if (game->mlx_connection == NULL)
		return ;
	game->mlx_window = mlx_new_window(game->mlx_connection,
			game->window_width, game->window_height, "Incredible game");
	if (game->mlx_window == NULL)
		return ;
	mlx_key_hook(game->mlx_window, handle_input, game);
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

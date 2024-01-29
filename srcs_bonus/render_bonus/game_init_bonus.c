/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:16:35 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/29 20:15:24 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	get_nb_coins(struct s_game *game)
{
	int	x;
	int	y;

	game->player->nb_coins = 0;
	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->player->nb_coins++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	get_player_pos(struct s_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player->pos_x = x;
				game->player->pos_y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	get_images(struct s_game *game)
{
	if (!game_init_images(game))
		program_exit(game);
	if (!game_init_images_player(game))
		program_exit(game);
	if (!game_init_images_enemy(game))
		program_exit(game);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		program_exit(game);
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

int	game_init(t_game *game, char **map)
{
	game->player = malloc(sizeof(t_player));
	game->mlx = malloc(sizeof(t_mlx));
	game->props = malloc(sizeof(t_props));
	if (!game->player || !game->mlx || !game->props)
		return (0);
	game->map = map;
	game_init_others(game);
	game->mlx->mlx_con = mlx_init();
	if (game->mlx->mlx_con == NULL)
		return (0);
	game->mlx->mlx_window = mlx_new_window(game->mlx->mlx_con,
			game->mlx->window_width, game->mlx->window_height, "Best game");
	if (game->mlx->mlx_window == NULL)
		return (0);
	get_images(game);
	mlx_key_hook(game->mlx->mlx_window, handle_input, game);
	mlx_hook(game->mlx->mlx_window, 17, 0, program_exit, game);
	return (1);
}

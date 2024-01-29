/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_movement_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:57:06 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/29 20:17:59 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	render_up(struct s_game *game)
{
	if (game->map[game->player->pos_y - 1][game->player->pos_x] == '1')
		return ;
	if (game->map[game->player->pos_y - 1][game->player->pos_x] == 'C')
	{
		game->map[game->player->pos_y - 1][game->player->pos_x] = '0';
		game->player->nb_coins--;
	}
	if (game->map[game->player->pos_y - 1][game->player->pos_x] == 'A')
	{
		display_fail(game);
		program_exit(game);
	}
	game->map[game->player->pos_y - 1][game->player->pos_x] = 'P';
	game->map[game->player->pos_y][game->player->pos_x] = '0';
	display_exit(game);
	get_player_pos(game);
	game->player->nb_moves += 1;
	game->player->move_done = 'u';
}

void	render_down(struct s_game *game)
{
	if (game->map[game->player->pos_y + 1][game->player->pos_x] == '1')
		return ;
	if (game->map[game->player->pos_y + 1][game->player->pos_x] == 'C')
	{
		game->map[game->player->pos_y + 1][game->player->pos_x] = '0';
		game->player->nb_coins--;
	}
	if (game->map[game->player->pos_y + 1][game->player->pos_x] == 'A')
	{
		display_fail(game);
		program_exit(game);
	}
	game->map[game->player->pos_y + 1][game->player->pos_x] = 'P';
	game->map[game->player->pos_y][game->player->pos_x] = '0';
	display_exit(game);
	get_player_pos(game);
	game->player->nb_moves += 1;
	game->player->move_done = 'd';
}

void	render_left(struct s_game *game)
{
	if (game->map[game->player->pos_y][game->player->pos_x - 1] == '1')
		return ;
	if (game->map[game->player->pos_y][game->player->pos_x - 1] == 'C')
	{
		game->map[game->player->pos_y][game->player->pos_x - 1] = '0';
		game->player->nb_coins--;
	}
	if (game->map[game->player->pos_y][game->player->pos_x - 1] == 'A')
	{
		display_fail(game);
		program_exit(game);
	}
	game->map[game->player->pos_y][game->player->pos_x - 1] = 'P';
	game->map[game->player->pos_y][game->player->pos_x] = '0';
	display_exit(game);
	get_player_pos(game);
	game->player->nb_moves += 1;
	game->player->move_done = 'l';
}

void	render_right(struct s_game *game)
{
	if (game->map[game->player->pos_y][game->player->pos_x + 1] == '1')
		return ;
	if (game->map[game->player->pos_y][game->player->pos_x + 1] == 'C')
	{
		game->map[game->player->pos_y][game->player->pos_x + 1] = '0';
		game->player->nb_coins--;
	}
	if (game->map[game->player->pos_y][game->player->pos_x + 1] == 'A')
	{
		display_fail(game);
		program_exit(game);
	}
	game->map[game->player->pos_y][game->player->pos_x + 1] = 'P';
	game->map[game->player->pos_y][game->player->pos_x] = '0';
	display_exit(game);
	get_player_pos(game);
	game->player->nb_moves += 1;
	game->player->move_done = 'r';
}

void	display_exit(struct s_game *game)
{
	if (game->player->pos_y == game->props->exit_pos_y
		&& game->player->pos_x == game->props->exit_pos_x)
		game->map[game->props->exit_pos_y][game->props->exit_pos_x] = 'E';
}

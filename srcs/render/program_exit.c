/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:10:07 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/25 22:19:09 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	program_exit(struct s_game *game)
{
	free_double_array(game->map);
	mlx_clear_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_image(game->mlx_connection, game->player_image);
	mlx_destroy_image(game->mlx_connection, game->coin_image);
	mlx_destroy_image(game->mlx_connection, game->wall_image);
	mlx_destroy_image(game->mlx_connection, game->ground_image);
	mlx_destroy_image(game->mlx_connection, game->exit_image);
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_display(game->mlx_connection);
	free(game->mlx_connection);
}

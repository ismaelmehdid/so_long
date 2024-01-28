/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:10:07 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/28 04:08:23 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(struct s_game *game)
{
	mlx_destroy_image(game->mlx->mlx_con, game->player->back_image);
	mlx_destroy_image(game->mlx->mlx_con, game->player->front_image);
	mlx_destroy_image(game->mlx->mlx_con, game->player->left_image);
	mlx_destroy_image(game->mlx->mlx_con, game->player->right_image);
	mlx_destroy_image(game->mlx->mlx_con, game->props->coin_image);
	mlx_destroy_image(game->mlx->mlx_con, game->props->wall_image);
	mlx_destroy_image(game->mlx->mlx_con, game->props->ground_image);
	mlx_destroy_image(game->mlx->mlx_con, game->props->exit_image);
}

int	program_exit(struct s_game *game)
{
	free_double_array(game->map);
	if (game->mlx->mlx_window)
	{
		mlx_clear_window(game->mlx->mlx_con, game->mlx->mlx_window);
		mlx_destroy_window(game->mlx->mlx_con, game->mlx->mlx_window);
		destroy_images(game);
		mlx_destroy_display(game->mlx->mlx_con);
	}
	if (game->mlx->mlx_con)
		free(game->mlx->mlx_con);
	if (game->mlx)
		free(game->mlx);
	if (game->player)
		free(game->player);
	if (game->props)
		free(game->props);
	exit(EXIT_SUCCESS);
	return (0);
}

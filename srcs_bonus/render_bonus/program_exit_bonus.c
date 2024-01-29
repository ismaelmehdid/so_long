/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:10:07 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/29 20:23:16 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	display_fail(struct s_game *game)
{
	ft_printf("\033[31m _______  _______ _________ _  \n");
	ft_printf("\033[31m(  ____ \\(  ___  )\\__   __/( \\ \n");
	ft_printf("\033[31m| (    \\/| (   ) |   ) (   | ( \n");
	ft_printf("\033[31m| (__    | (___) |   | |   | | \n");
	ft_printf("\033[31m|  __)   |  ___  |   | |   | | \n");
	ft_printf("\033[31m| (      | (   ) |   | |   | | \n");
	ft_printf("\033[31m| )      | )   ( |___) (___| (____/\\ \n");
	ft_printf("\033[31m|/       |/     \\|\\_______/(_______/ \n");
	ft_printf("\033[31mNext time avoid the enemies, you moved %d times\n",
		game->player->nb_moves + 1);
}

void	display_success(struct s_game *game)
{
	ft_printf(" _____ _   _ _____  _____  _____ _____ _____ \n");
	ft_printf("/  ___| | | /  __ \\/  __ \\|  ___/  ___/  ___|\n");
	ft_printf("\\ `--.| | | | /  \\/| /  \\/| |__ \\ `--.\\ `--. \n");
	ft_printf(" `--. \\ | | | |    | |    |  __| `--. \\`--. \\\n");
	ft_printf("/\\__/ / |_| | \\__/\\| \\__/\\| |___/\\__/ /\\__/ /\n");
	ft_printf("\\____/ \\___/ \\____/ \\____/\\____/\\____/\\____/ \n");
	ft_printf("Your score : %d moves\n", game->player->nb_moves);
}

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
	mlx_destroy_image(game->mlx->mlx_con, game->props->enemy_image_1);
	mlx_destroy_image(game->mlx->mlx_con, game->props->enemy_image_2);
	mlx_destroy_image(game->mlx->mlx_con, game->props->enemy_image_3);
	mlx_destroy_image(game->mlx->mlx_con, game->props->enemy_image_4);
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

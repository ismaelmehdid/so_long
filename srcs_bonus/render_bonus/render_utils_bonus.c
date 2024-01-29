/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:19:24 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/29 15:48:37 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	double_array_size(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

void	get_exit_pos(struct s_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->props->exit_pos_x = 0;
	game->props->exit_pos_y = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'E')
			{
				game->props->exit_pos_x = i;
				game->props->exit_pos_y = j;
				return ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

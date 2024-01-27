/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_playable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:50:46 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/27 23:11:56 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	flood_fill(int x, int y, struct s_floodfill *context)
{
	int	linear_index;

	linear_index = get_index(x, y, context->cols);
	if (x < 0 || y < 0 || y >= context->rows || x >= context->cols
		|| context->visited[linear_index] || context->map[linear_index] == '1')
		return ;
	context->visited[linear_index] = true;
	flood_fill(x + 1, y, context);
	flood_fill(x - 1, y, context);
	flood_fill(x, y + 1, context);
	flood_fill(x, y - 1, context);
}

bool	is_map_playable(char **map)
{
	t_floodfill	context;
	int			rows;
	int			columns;
	int			start_x;
	int			start_y;

	rows = 0;
	columns = ft_strlen(map[0]);
	rows = height_double_array(map);
	get_player_spawn(map, &start_x, &start_y, rows);
	context.rows = rows;
	context.cols = columns;
	context.map = concatenate_strings(map);
	context.visited = malloc(rows * columns * sizeof(bool));
	init_visited(&context);
	flood_fill(start_x, start_y, &context);
	if (!all_reachable(columns, rows, context, map))
	{
		free(context.map);
		free(context.visited);
		return (false);
	}
	free(context.map);
	free(context.visited);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_playable_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:19:25 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/28 00:45:24 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_spawn(char **map, int *x, int *y, int rows)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*x = 0;
	*y = 0;
	while (j < rows)
	{
		while (i < ft_strlen(map[0]))
		{
			if (map[j][i] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	init_visited(struct s_floodfill *context)
{
	int	i;

	i = 0;
	while (i < context->rows * context->cols)
	{
		context->visited[i] = false;
		i++;
	}
}

int	get_index(int x, int y, int num_cols)
{
	int	res;

	res = y * num_cols + x;
	return (res);
}

bool	all_reachable(int columns, int rows, t_floodfill context, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < rows)
	{
		while (i < columns)
		{
			if ((map[j][i] == 'C' || map[j][i] == 'E') &&
				(!context.visited[get_index(i, j, columns)]))
				return (false);
			i++;
		}
		i = 0;
		j++;
	}
	return (true);
}

char	*concatenate_strings(char **strings)
{
	char	*result;
	int		i;
	int		e;
	int		j;

	j = 0;
	e = 0;
	i = 0;
	while (strings[i])
		j += ft_strlen(strings[i++]);
	result = malloc(j + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 0;
	j = 0;
	while (strings[j])
	{
		while (strings[j][i])
			result[e++] = strings[j][i++];
		i = 0;
		j++;
	}
	return (result);
}

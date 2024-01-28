/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_props.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:14:53 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/28 00:45:13 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_is_rectangle(char **map)
{
	int	height;
	int	lenght;
	int	j;

	if (!map)
		return (0);
	height = 0;
	lenght = ft_strlen(map[0]);
	j = 0;
	while (map[height])
		height++;
	if (height < 3 || lenght == height)
		return (0);
	while (map[j])
	{
		if (ft_strlen(map[j]) != lenght)
			return (0);
		j++;
	}
	return (1);
}

int	map_is_closed(char **map)
{
	int	j;
	int	lenght;

	if (!map)
		return (0);
	j = 1;
	lenght = ft_strlen(map[0]);
	if (!is_only_one(map[0]))
		return (0);
	while (map[j + 1])
	{
		if (map[j][0] != '1' || map[j][lenght - 1] != '1')
			return (0);
		j++;
	}
	if (!is_only_one(map[j]))
		return (0);
	return (1);
}

void	init_var(int *exit, int *collectible, int *spawn, int *j)
{
	*exit = 0;
	*collectible = 0;
	*spawn = 0;
	*j = 0;
}

int	map_props_nbr(char **map)
{
	int	exit;
	int	collectible;
	int	spawn;
	int	j;
	int	i;

	init_var(&exit, &collectible, &spawn, &j);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				exit++;
			else if (map[j][i] == 'C')
				collectible++;
			else if (map[j][i] == 'P')
				spawn++;
			i++;
		}
		j++;
	}
	if (exit != 1 || spawn != 1 || collectible < 1)
		return (0);
	return (1);
}

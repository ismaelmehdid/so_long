/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:57:31 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/26 17:40:18 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	map_path_is_correct(char *path)
{
	int		i;
	int		j;
	int		fd;
	char	*file_extention;

	file_extention = ".ber";
	j = ft_strlen(file_extention) - 1;
	i = ft_strlen(path) - 1;
	while (path[i] != '.' && i >= 0)
	{
		if (path[i] != file_extention[j])
			return (0);
		i--;
		j--;
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

char	**map_is_correct(char *path)
{
	int		fd;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = map_convert(fd, path);
	if (!map)
		return (NULL);
	map = map_croping(map);
	if (!map)
		return (NULL);
	if (!map_is_rectangle(map) || !map_is_closed(map)
		|| !map_props_nbr(map))
	{
		free_double_array(map);
		return (NULL);
	}
	return (map);
}

char	**map_convert(int fd, char *path)
{
	char	**map;
	char	*line;
	int		j;
	int		nblines;

	nblines = count_lines(path);
	j = 0;
	map = malloc(sizeof(char *) * (nblines + 1));
	if (!map)
		return (NULL);
	while (j < nblines)
	{
		line = get_next_line(fd);
		map[j] = ft_strdup_c(line);
		free (line);
		j++;
	}
	map[j] = NULL;
	return (map);
}

char	**map_croping(char **map)
{
	char	**croped;
	int		height;
	int		index_start;
	int		index_end;
	int		j;

	j = 0;
	map_height(map, &height, &index_start, &index_end);
	croped = malloc(sizeof(char *) * (height + 1));
	while (index_start <= index_end && map[index_start] && croped)
	{
		croped[j] = ft_strdup(map[index_start++]);
		if (!croped[j++])
		{
			free_double_array(croped);
			return (NULL);
		}
	}
	if (croped)
		croped[j] = NULL;
	free_double_array(map);
	return (croped);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:07:21 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/19 22:04:58 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_only_one(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	last_line(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	if (line[i] == '\n')
		return (0);
	return (1);
}

int	map_is_rectangle(int fd)
{
	char	*line;
	int		lenght;
	int		height;

	line = get_next_line(fd);
	if (!line)
		return (0);
	lenght = ft_strlen(line);
	height = 1;
	while (line)
	{
		free (line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!last_line(line) && ft_strlen(line) != lenght)
			return (0);
		if (last_line(line) && ft_strlen(line) + 1 != lenght)
			return (0);
		height++;
	}
	free (line);
	if (height <= 2 || lenght <= 2 || height >= lenght)
		return (0);
	return (1);
}

char **map_convert(int fd, char *path)
{
	char	**map;
	int		size;
	char	*line;

	map = NULL;
	size = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		size++;
	}
	free(line);
	close (fd);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	return (map);
}
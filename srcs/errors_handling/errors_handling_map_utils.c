/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_map_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:40:47 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/24 22:53:42 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_only_one(char *line)
{
	int	i;

	i = 0;
	if (!line || ft_strlen(line) == 0)
		return (0);
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	count_lines(char *path)
{
	int		fd;
	char	ch;
	int		lines;

	lines = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
			lines++;
	}
	lines++;
	close(fd);
	return (lines);
}

char	*ft_strdup_c(char *buffer)
{
	int		size;
	char	*copy;
	int		i;

	i = 0;
	size = 0;
	if (!buffer || ft_strlen(buffer) == 0)
		return (NULL);
	while (buffer[size] != '\n' && buffer[size])
		size++;
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = buffer[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	map_height(char **map, int *height, int *indexStart, int *indexEnd)
{
	int	i;

	i = 0;
	*height = 0;
	*indexStart = 0;
	*indexEnd = 0;
	while (!is_only_one(map[i]) && map[i])
		i++;
	while (is_only_one(map[i]) && map[i])
		i++;
	*indexStart = i - 1;
	(*height)++;
	while (!is_only_one(map[i]) && map[i])
	{
		i++;
		(*height)++;
	}
	(*height)++;
	*indexEnd = i;
}

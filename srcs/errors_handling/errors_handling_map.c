/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:57:31 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/19 22:05:47 by ismaelmehdi      ###   ########.fr       */
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

int	map_is_correct(char *path)
{
	int		fd;
	//char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	map_convert(fd, path);
	if (!map_is_rectangle(fd))
	{
		close (fd);
		return (0);
	}
	return (1);
}

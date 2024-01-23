/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:56 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/23 17:55:20 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h> //TODO : delete
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* Error handling*/
char	**errors_handling(int argc, char **argv);
int	map_path_is_correct(char *path);
char	**map_is_correct(char *path);
//int	map_is_rectangle(int fd);
//int	map_is_closed(int fd);
char **map_convert(int fd, char *path);
char	*ft_strdup_c(char *buffer);
int		count_lines(char *path);
int		is_only_one(char *line);
void	free_double_array(char **array);
char	**map_croping(char **map);
void	map_height(char **map, int *height, int *indexStart, int *indexEnd);
int		map_is_closed(char **map);
int		map_is_rectangle(char **map);
int		map_props_nbr(char **map);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:56 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/19 22:02:04 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h> //TODO : delete
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* Error handling*/
int	errors_handling(int argc, char **argv);
int	map_path_is_correct(char *path);
int	map_is_correct(char *path);
int	map_is_rectangle(int fd);
int	map_is_closed(int fd);
char **map_convert(int fd, char *path);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:56 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/24 23:01:53 by ismaelmehdi      ###   ########.fr       */
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

typedef struct s_game{
	void	*mlx_connection;
	void	*mlx_window;
	int		window_width;
	int		window_height;
	char	**map;
	void	*wall_image;
	void	*ground_image;
	void	*exit_image;
	void	*player_image;
	void	*coin_image;
	int		width_image;
	int		height_image;
}t_game;

/* Error handling*/
char	**errors_handling(int argc, char **argv);
int		map_path_is_correct(char *path);
char	**map_is_correct(char *path);
char	**map_convert(int fd, char *path);
char	*ft_strdup_c(char *buffer);
int		count_lines(char *path);
int		is_only_one(char *line);
void	free_double_array(char **array);
char	**map_croping(char **map);
void	map_height(char **map, int *height, int *indexStart, int *indexEnd);
int		map_is_closed(char **map);
int		map_is_rectangle(char **map);
int		map_props_nbr(char **map);
/*---------------*/

/*Init the game*/
void	game_init(struct s_game *game, char **map);
int		double_array_size(char **map);
void	game_init_images(struct s_game *game);
void	game_render(struct s_game *game);
void	put_image(struct s_game *game, char prop, int x, int y);
/*-------------*/

#endif
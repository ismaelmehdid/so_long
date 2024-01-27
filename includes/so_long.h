/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:56 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/27 23:26:17 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <X11/keysym.h>
# include <stdio.h> //TODO : delete
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_floodfill{
    int rows;
    int cols;
    bool *visited;
    char *map;
}t_floodfill;

typedef struct s_enemy_images{
	void	*enemy_image_one;
	void	*enemy_image_two;
	void	*enemy_image_three;
	void	*enemy_image_four;	
}t_enemy_images;

typedef struct s_game{
	void	*mlx_connection;
	void	*mlx_window;
	int		window_width;
	int		window_height;
	char	**map;
	void	*wall_image;
	void	*ground_image;
	void	*exit_image;
	void	*player_front_image;
	void	*player_back_image;
	void	*player_right_image;
	void	*player_left_image;
	void	*coin_image;
	int		width_image;
	int		height_image;
	int		player_pos_x;
	int		player_pos_y;
	int		nb_moves;
	int		nb_coins;
	int		enemy_pos_x;
	int		enemy_pos_y;
	t_enemy_images *enemy_images;
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
bool	props_are_valid(char **map);
/*--playable?--*/
void	get_player_spawn(char **map, int *x, int *y, int rows);
void	init_visited(struct s_floodfill *context);
int		get_index(int row, int col, int num_cols);
bool	all_reachable(int columns, int rows, t_floodfill context, char **map);
bool	is_map_playable(char **map);
char	*concatenate_strings(char **strings);
int		height_double_array(char **array);
/*-------------*/

/*Init the game*/
void	game_init(t_game *game, char **map, t_enemy_images *enemy_images);
int		double_array_size(char **map);
void	game_init_images(struct s_game *game);
void	game_init_images_player(struct s_game *game);
void	game_init_images_enemy(struct s_game *game);
void	game_render(struct s_game *game);
void	put_image(struct s_game *game, char prop, int x, int y);
void	get_player_pos(struct s_game *game);
int		enemy_render(struct s_game *game);

void	render_up(struct s_game *game);
void	render_down(struct s_game *game);
void	render_left(struct s_game *game);
void	render_right(struct s_game *game);
void	get_nb_coins(struct s_game *game);

int	program_exit(struct s_game *game);

#endif
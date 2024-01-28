/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:56 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/28 03:51:37 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_floodfill{
	int		rows;
	int		cols;
	bool	*visited;
	char	*map;
}t_floodfill;

typedef struct s_game{
	struct s_mlx		*mlx;
	struct s_player		*player;
	struct s_props		*props;
	char				**map;
}t_game;

typedef struct s_player{
	void	*front_image;
	void	*back_image;
	void	*right_image;
	void	*left_image;
	int		pos_x;
	int		pos_y;
	int		nb_coins;
	int		nb_moves;
}t_player;

typedef struct s_props{
	void	*wall_image;
	void	*ground_image;
	void	*exit_image;
	void	*coin_image;
}t_props;

typedef struct s_mlx{
	void	*mlx_con;
	void	*mlx_window;
	int		width_image;
	int		height_image;
	int		window_width;
	int		window_height;
}t_mlx;

/* Error handling*/
char	**errors_handling(int argc, char **argv);
int		map_path_is_correct(char *path);
char	**map_is_correct(char *path);
char	**map_convert(int fd, char *path);
char	**map_croping(char **map);

void	get_player_spawn(char **map, int *x, int *y, int rows);
void	init_visited(struct s_floodfill *context);
int		get_index(int row, int col, int num_cols);
bool	all_reachable(int columns, int rows, t_floodfill context, char **map);
bool	is_map_playable(char **map);
char	*concatenate_strings(char **strings);
int		height_double_array(char **array);

/* Error handling utils*/
char	*ft_strdup_c(char *buffer);
int		count_lines(char *path);
void	map_height(char **map, int *height, int *indexStart, int *indexEnd);
int		is_only_one(char *line);
int		map_is_closed(char **map);
int		map_is_rectangle(char **map);
int		map_props_nbr(char **map);
bool	props_are_valid(char **map);

/*Init the game*/
int		game_init(t_game *game, char **map);
int		game_init_images(struct s_game *game);
int		game_init_images_player(struct s_game *game);
void	game_render(struct s_game *game);
void	put_image(struct s_game *game, char prop, int x, int y);
void	render_up(struct s_game *game);
void	render_down(struct s_game *game);
void	render_left(struct s_game *game);
void	render_right(struct s_game *game);

void	get_player_pos(struct s_game *game);
void	get_nb_coins(struct s_game *game);

/*Other utils*/

int		program_exit(struct s_game *game);
void	free_double_array(char **array);
int		double_array_size(char **map);

#endif
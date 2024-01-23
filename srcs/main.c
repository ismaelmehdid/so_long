/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:05:45 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/23 19:55:16 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	double_array_lenght(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	**map;
	void	*mlx;

	if (!(map = errors_handling(argc, argv)))
	{
		write(2, "Either bad arguments, or your map isn't correct\n", 48);
		exit(EXIT_FAILURE);
	}
	mlx = mlx_init();
	if(NULL == mlx)
		return (0);

	mlx_loop(mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:15:42 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/25 17:03:58 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**errors_handling(int argc, char **argv)
{
	char	**map;

	map = NULL;
	if (argc != 2)
		return (NULL);
	if (!map_path_is_correct(argv[1]))
		return (NULL);
	map = map_is_correct(argv[1]);
	if (!map)
		return (NULL);
	return (map);
}

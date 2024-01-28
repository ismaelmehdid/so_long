/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:19:24 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/28 03:52:20 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	double_array_size(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

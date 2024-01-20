/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:15:42 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/20 17:33:29 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	errors_handling(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!map_path_is_correct(argv[1]))
		return (0);
	if (!map_is_correct(argv[1]))
		return (0);
	//TODO : all xpm are correct ?
	return (1);
}

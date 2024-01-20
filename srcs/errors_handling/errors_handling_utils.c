/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:07:21 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/20 17:44:32 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_double_array(char **array)
{
	int	i;
	i = 0;
	
	if (!array)
		return ;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 05:55:59 by acharik           #+#    #+#             */
/*   Updated: 2025/04/24 05:56:00 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_field_of_view(t_mlx *wind, char in_map)
{
	if (in_map == 'N')
		wind->field_of_view = 90.0;
	else if (in_map == 'S')
		wind->field_of_view = 270.00;
	else if (in_map == 'E')
		wind->field_of_view = 360.0;
	else if (in_map == 'W')
		wind->field_of_view = 180.0;
}

void	get_player_position(t_mlx *wind)
{
	int	i;
	int	j;

	i = 0;
	while (wind->map[i])
	{
		j = 0;
		while (wind->map[i][j])
		{
			if (wind->map[i][j] == 'N' || wind->map[i][j] == 'S'
				|| wind->map[i][j] == 'W' || wind->map[i][j] == 'E')
			{
				set_field_of_view(wind, wind->map[i][j]);
				wind->map[i][j] = '0';
				wind->y_player = i * 64;
				wind->x_player = j * 64;
				break ;
			}
			j++;
		}
		i++;
	}
}

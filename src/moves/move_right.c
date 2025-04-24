/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 05:55:09 by acharik           #+#    #+#             */
/*   Updated: 2025/04/24 05:55:10 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../../cub3d.h"

void	move_right(t_mlx *wind)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;

	y_step = sin((wind->field_of_view + 90) * M_PI / 180) * PX_MOVE;
	x_step = cos((wind->field_of_view + 90) * M_PI / 180) * PX_MOVE;
	y_map = (int)(wind->y_player + y_step) / WALL_DIM;
	x_map = (int)(wind->x_player + x_step) / WALL_DIM;
	if (wind->map[y_map][x_map] == '0' && wind->map[(int)(wind->y_player / WALL_DIM)][x_map] == '0')
	{
		wind->x_player += x_step;
		wind->y_player += y_step;
	}
}

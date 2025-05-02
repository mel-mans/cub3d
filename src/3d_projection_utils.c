/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 05:55:17 by acharik           #+#    #+#             */
/*   Updated: 2025/04/24 05:55:18 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	calculate_distance(double y_player, double x_player, double y_wall,
		double x_wall)
{
	return (sqrt(((x_player - x_wall) * (x_player - x_wall)) + ((y_player
					- y_wall) * (y_player - y_wall))));
}

double	fix_fisheye(t_mlx *mlx, double angle)
{
	mlx->corrected_distance = mlx->distance * cos((angle - mlx->field_of_view)
			* (M_PI / 180));
	return (mlx->corrected_distance);
}

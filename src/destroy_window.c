/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 05:55:44 by acharik           #+#    #+#             */
/*   Updated: 2025/04/24 05:55:45 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy_window(t_mlx *wind)
{
	mlx_destroy_window(wind->mlx, wind->window);
	printf("Thanks for playing with us\n");
	exit(0);
}

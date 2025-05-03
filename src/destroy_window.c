/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mans <mel-mans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 05:55:44 by acharik           #+#    #+#             */
/*   Updated: 2025/05/03 18:16:58 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy_window(t_mlx *wind)
{
	mlx_destroy_window(wind->mlx, wind->window);
	mlx_destroy_image(wind->mlx, wind->n_xpm);
	mlx_destroy_image(wind->mlx, wind->s_xpm);
	mlx_destroy_image(wind->mlx, wind->e_xpm);
	mlx_destroy_image(wind->mlx, wind->w_xpm);
	mlx_destroy_display(wind->mlx);
	free(wind->mlx);
	printf("Thanks for playing with us\n");
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 05:55:35 by acharik           #+#    #+#             */
/*   Updated: 2025/04/24 05:55:36 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_mlx		wind;
	t_data_par	*parsing;

	if (ac == 2)
	{
		parsing = malloc(sizeof(t_data_par));
		ft_parsing(ac, av, parsing);
		wind.parsing = parsing;
		wind.map = parsing->maze;
		wind.mlx = mlx_init();
		wind.window = mlx_new_window(wind.mlx, WIN_W, WIN_H, "Cub3D");
		images_to_xpm(&wind);
		get_player_position(&wind);
		projecting_rays(&wind);
		mlx_hook(wind.window, 2, 1L << 0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window, &wind);
		mlx_loop(wind.mlx);
	}
	else
		printf("Nbr of Args");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:04:48 by acharik           #+#    #+#             */
/*   Updated: 2025/05/03 17:57:39 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parsing.h"

void	check_line(t_data_par *parsing, int index, int *player_index)
{
	int		i;
	char	*line;

	i = 0;
	line = parsing->maze[index];
	while (i < (int)ft_strlen(line))
	{
		if (line[i] == 'S' || line[i] == 'N' || line[i] == 'E'
			|| line[i] == 'W')
		{
			around_ps(parsing, i, index);
			(*player_index)++;
		}
		if (line[i] == '0')
		{
			if (around_zero(parsing, index, line, i))
				error_line(parsing);
		}
		else if (check_possiblty(line[i]))
			error_line(parsing);
		i++;
	}
}

void	check_maze_player(t_data_par *parsing)
{
	int	i;
	int	player_index;

	i = 0;
	player_index = 0;
	while (parsing->maze[i])
	{
		if (i == 0 && true_line(parsing->maze[i]))
			error_line(parsing);
		else
			check_line(parsing, i, &player_index);
		if (player_index > 1)
			error_map(parsing);
		i++;
	}
	if (player_index == 0)
		error_map(parsing);
}

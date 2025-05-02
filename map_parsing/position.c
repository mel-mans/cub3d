/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:06:14 by acharik           #+#    #+#             */
/*   Updated: 2025/04/23 23:06:15 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parsing.h"

int	around_zero(t_data_par *parsing, int index, char *line, int i)
{
	if (i >= (int)(ft_strlen(parsing->maze[index + 1])) || (parsing->maze[index
			+ 1] == 0 || index - 1 < 0 || line[i - 1] == ' ' || line[i
			+ 1] == ' ' || line[i + 1] == '\0' || parsing->maze[index
			- 1][i] == ' ' || parsing->maze[index + 1][i] == '\0'
			|| parsing->maze[index + 1][i] == ' '))
	{
		return (1);
	}
	return (0);
}

void	around_ps(t_data_par *parsing, int i, int index)
{
	if (parsing->maze[index + 1] == 0 || index - 1 < 0 || parsing->maze[index][i
		- 1] == ' ' || parsing->maze[index][i + 1] == ' '
		|| parsing->maze[index][i + 1] == '\0' || parsing->maze[index
		- 1][i] == ' ' || parsing->maze[index + 1][i] == '\0'
		|| parsing->maze[index + 1][i] == ' ')
	{
		error_line(parsing);
	}
}

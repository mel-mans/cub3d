/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:06:21 by acharik           #+#    #+#             */
/*   Updated: 2025/04/23 23:06:22 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parsing.h"

void	aff_line(t_data_par *parsing, t_index *index, char *line)
{
	if (parsing->north_path == 0 || parsing->south_path == 0
		|| parsing->west_path == 0 || parsing->east_path == 0)
	{
		printf(" error texture  %d \n", index->n_derc);
		exit(0);
	}
	if (parsing->ceiling_color == -1 || parsing->floor_color == -1
		|| index->n_color != 2)
		error_color(parsing);
	parsing->maze[index->maze_index] = ft_strdup(line);
	index->maze_index++;
}

void	get_info_map(t_data_par *parsing, char *line, t_index *index,
		int *n_tex)
{
	char	*ptr;

	ptr = ft_strtrim(line, " ");
	if (check_possiblty_tex(ptr))
		texture_value(parsing, ptr, n_tex);
	else if (!ft_strncmp(ptr, "F ", 2) || !ft_strncmp(ptr, "C ", 2))
		get_color_values(parsing, ptr, index);
	else if ((ptr[0] == '1' || ptr[0] == '0' || index->maze_index != 0))
	{
		if (ptr[0] == '1' || ptr[0] == '0')
			aff_line(parsing, index, line);
		free(ptr);
		ptr = 0;
	}
	else
		free(ptr);
	free(line);
}

void	init_index(t_index *i)
{
	i->maze_index = 0;
	i->n_color = 0;
	i->n_derc = 0;
	i->new_line = 0;
}

void	read_map(char *file, t_data_par *parsing)
{
	char	*line;
	int		fd;
	char	*ptr;
	int		n_tex;
	t_index	i;

	n_tex = 0;
	line = 0;
	init_index(&i);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		ptr = line;
		if (line == 0)
			break ;
		if (line[0] == '\n' && i.maze_index != 0)
			error_map(parsing);
		line = ft_strtrim(line, "\n");
		get_info_map(parsing, line, &i, &n_tex);
		free(ptr);
	}
	parsing->maze[i.maze_index] = 0;
	check_maze_player(parsing);
}

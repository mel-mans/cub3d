/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:06:29 by acharik           #+#    #+#             */
/*   Updated: 2025/04/23 23:06:30 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "./includ/map_parsing.h"

char	*get_path_check(char *line, char *ser)
{
	char	*path;
	char	*tmp;
	int		fd;

	tmp = line;
	path = ft_strtrim(line, ser);
	free(tmp);
	line = ft_strtrim(path, " ");
	free(path);
	fd = open(line, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: Could not open texture");
		exit(0);
	}
	close(fd);
	return (line);
}

void	texture_value(t_data_par *parsing, char *line, int *nbr )
{
	if (*nbr > 3)
	{
		free(line);
		printf("error");
		exit(0);
	}
	if (!ft_strncmp(line, "SO ", 3))
		parsing->south_path = get_path_check(line, "SO");
	else if (!ft_strncmp(line, "NO ", 3))
		parsing->north_path = get_path_check(line, "NO");
	else if (!ft_strncmp(line, "WE ", 3))
		parsing->west_path = get_path_check(line, "WE");
	else if (!ft_strncmp(line, "EA ", 3))
		parsing->east_path = get_path_check(line, "EA");
	else
	{
		free(line);
		return ;
	}
	(*nbr)++;
}

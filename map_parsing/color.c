/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:05:24 by acharik           #+#    #+#             */
/*   Updated: 2025/04/23 23:05:27 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parsing.h"

int	stat_color(char s, int *vergul, int *nbr, int *rgb)
{
	if (s >= '0' && s <= '9')
		(*nbr) = (*nbr) * 10 + s - '0';
	else if (s == ',')
	{
		if ((*vergul) < 3)
			rgb[(*vergul)] = *nbr;
		(*vergul)++;
		(*nbr) = 0;
	}
	else if (s != ' ')
	{
		*vergul = 0;
		return (0);
	}
	return (1);
}

int	check_verg(char *line)
{
	int	index;
	int	vergul;
	int	nbr;
	int	c[3];

	index = 0;
	vergul = 0;
	nbr = 0;
	while (line[index])
	{
		if (stat_color(line[index], &vergul, &nbr, c) == 0)
			break ;
		index++;
	}
	if (vergul == 2 && c[0] <= 255 && c[1] <= 255 && nbr <= 255)
		return (((c[0] << 16) + (c[1] << 8) + nbr));
	return (-1);
}

int	ft_get_color(char *line, char *str)
{
	char	*str_color;
	int		color;

	color = -1;
	str_color = ft_strtrim(line, str);
	if (str_color[0] != ',' && str_color[ft_strlen(str_color) - 1] != ',')
		color = check_verg(str_color);
	free(line);
	free(str_color);
	return (color);
}

void	get_color_values(t_data_par *parsing, char *line, t_index *index)
{
	if (!ft_strncmp(line, "F ", 2))
		parsing->floor_color = ft_get_color(line, " F");
	else if (!ft_strncmp(line, "C ", 2))
		parsing->ceiling_color = ft_get_color(line, " C");
	index->n_color++;
}

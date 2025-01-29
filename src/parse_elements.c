#include "cub3d.h"

static int	parse_texture(char *line, t_texture *texture)
{
	char	*path;
	
	path = ft_strtrim(line, " \t\n\v\f\r");
	if (!path)
		return (-1);
	if (!ft_strendswith(path, ".xpm"))
	{
		free(path);
		return (-1);
	}
	texture->path = path;
	return (0);
}

static int	parse_color(char *line, int *color)
{
	char	**parts;
	int		rgb[3];
	int		i;
	char	*trimmed;

	parts = ft_split(line, ',');
	if (!parts)
		return (-1);
	i = 0;
	while (parts[i] && i < 3)
	{
		trimmed = ft_strtrim(parts[i], " \t\n\v\f\r");
		rgb[i] = ft_atoi(trimmed);
		free(trimmed);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			ft_free_split(parts);
			return (-1);
		}
		i++;
	}
	ft_free_split(parts);
	if (i != 3)
		return (-1);
	*color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (0);
}

static int	parse_line(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (parse_texture(line + 3, &game->north));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (parse_texture(line + 3, &game->south));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (parse_texture(line + 3, &game->west));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (parse_texture(line + 3, &game->east));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_color(line + 2, &game->floor_color));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_color(line + 2, &game->ceiling_color));
	return (0);
}

int	parse_elements(int fd, t_game *game)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) > 0)
		{
			if (parse_line(line, game) < 0)
			{
				free(line);
				return (-1);
			}
		}
		free(line);
	}
	return (ret);
}
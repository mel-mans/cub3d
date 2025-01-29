#include "cub3d.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' ||
			c == 'E' || c == 'W' || c == ' ');
}

static int	validate_map_line(char *line, int *width)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		if (!is_valid_char(line[i]))
			return (-1);
		i++;
	}
	if (len > *width)
		*width = len;
	return (0);
}

static int	add_map_line(t_game *game, char *line)
{
	char	**new_grid;
	int		i;

	new_grid = malloc(sizeof(char *) * (game->map.height + 2));
	if (!new_grid)
		return (-1);
	i = 0;
	while (i < game->map.height)
	{
		new_grid[i] = game->map.grid[i];
		i++;
	}
	new_grid[i] = ft_strdup(line);
	if (!new_grid[i])
	{
		free(new_grid);
		return (-1);
	}
	new_grid[i + 1] = NULL;
	free(game->map.grid);
	game->map.grid = new_grid;
	game->map.height++;
	return (0);
}

int	parse_map(int fd, t_game *game)
{
	char	*line;
	int		ret;

	game->map.width = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (validate_map_line(line, &game->map.width) < 0 ||
			add_map_line(game, line) < 0)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	return (validate_map(game));
}

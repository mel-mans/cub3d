#include "cub3d.h"

static int	check_borders(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((map->grid[y][x] == '0' ||
				ft_strchr("NSEW", map->grid[y][x])) &&
				(y == 0 || y == map->height - 1 ||
				x == 0 || x == map->width - 1 ||
				map->grid[y - 1][x] == ' ' ||
				map->grid[y + 1][x] == ' ' ||
				map->grid[y][x - 1] == ' ' ||
				map->grid[y][x + 1] == ' '))
				return (-1);
		}
		x++;
	}
	y++;
	return (0);
}

static int	find_player(t_map *map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (ft_strchr("NSEW", map->grid[y][x]))
			{
				map->player_x = x;
				map->player_y = y;
				map->player_dir = map->grid[y][x];
				count++;
			}
			x++;
		}
		y++;
	}
	return (count == 1 ? 0 : -1);
}

int	validate_map(t_game *game)
{
	if (game->map.height < 3 || game->map.width < 3)
		return (-1);
	if (check_borders(&game->map) < 0)
		return (-1);
	if (find_player(&game->map) < 0)
		return (-1);
	return (0);
}
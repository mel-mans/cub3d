#include "cub3d.h"

static void	init_game(t_game *game)
{
	ft_memset(&game->north, 0, sizeof(t_texture));
	ft_memset(&game->south, 0, sizeof(t_texture));
	ft_memset(&game->west, 0, sizeof(t_texture));
	ft_memset(&game->east, 0, sizeof(t_texture));
	game->floor_color = -1;
	game->ceiling_color = -1;
	ft_memset(&game->map, 0, sizeof(t_map));
}

void	free_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	free(game->north.path);
	free(game->south.path);
	free(game->west.path);
	free(game->east.path);
	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height)
			free(game->map.grid[i++]);
		free(game->map.grid);
	}
	free(game);
}

t_game	*parse_cub_file(char *filename)
{
	t_game	*game;
	int		fd;

	if (!filename || !ft_strendswith(filename, ".cub"))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	init_game(game);
	if (parse_elements(fd, game) < 0)
	{
		free_game(game);
		return (NULL);
	}
	close(fd);
	return (game);
}

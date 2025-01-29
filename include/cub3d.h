#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_texture
{
	char	*path;
	int		*pixels;
	int		width;
	int		height;
}	t_texture;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_map;

typedef struct s_game
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	int			floor_color;
	int			ceiling_color;
	t_map		map;
}	t_game;

// Parser functions
t_game	*parse_cub_file(char *filename);
void	free_game(t_game *game);
int		parse_elements(int fd, t_game *game);
int		validate_map(t_game *game);

#endif
#include "../cub3d.h"

void	rotate_left(t_mlx *wind)
{
	wind->field_of_view -= PX_ROTATION;
	if (wind->field_of_view > 360.0)
		wind->field_of_view = 0;
	if (wind->field_of_view < 0)
		wind->field_of_view = 360.0;
}

void	rotate_right(t_mlx *wind)
{
	wind->field_of_view += PX_ROTATION;
	if (wind->field_of_view > 360.0)
		wind->field_of_view = 0;
	if (wind->field_of_view < 0)
		wind->field_of_view = 360.0;
}

int	get_keys(int press, t_mlx *wind)
{
	if (press == 65363)
		rotate_right(wind);
	if (press == 65361)
		rotate_left(wind);
	if (press == 100)
		move_right(wind);
	if (press == 97)
		move_left(wind);
	if (press == 119)
		move_forward(wind);
	if (press == 115)
		move_backword(wind);
	if (press == 65307)
		destroy_window(wind);
	projecting_rays(wind);
	return (0);
}

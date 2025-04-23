#include "./includ/map_parsing.h"

void	error_line(t_data_par *parsing)
{
	free(parsing);
	printf(" error line \n");
	exit(1);
}

void	error_map(t_data_par *parsing)
{
	free(parsing);
	printf(" error map \n");
	exit(1);
}

void	error_color(t_data_par *parsing)
{
	free(parsing);
	printf(" error color \n");
	exit(1);
}

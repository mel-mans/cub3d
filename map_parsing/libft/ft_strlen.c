#include "../includ/map_parsing.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str != 0 && str[i] != '\0')
		i++;
	return (i);
}

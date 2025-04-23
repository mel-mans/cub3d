#include "../includ/map_parsing.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (!s || !fd)
		return ;
	while (s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}

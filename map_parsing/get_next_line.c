/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:45:34 by mel-mans          #+#    #+#             */
/*   Updated: 2025/05/03 21:45:38 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parsing.h"

char	*ft_strchr2(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*get_line_of_text(char *text)
{
	int		i;

	i = 0;
	if (text[i] == '\0')
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	return (ft_substr(text, 0, i + 1));
}

char	*save_next_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0')
	{
		free (line);
		return (NULL);
	}
	str = ft_substr(ft_strchr2(line, '\n') + 1, 0, ft_strlen(line));
	free(line);
	return (str);
}

char	*help_get_next_line(int fd, char *buff_line)
{
	int			red_byt;
	char		*buff;

	red_byt = 1;
	buff = malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!buff)
		return (NULL);
	while (check_line2(buff_line) != 1 && red_byt != 0)
	{
		red_byt = read(fd, buff, BUFFER_SIZE);
		if (red_byt == -1)
		{
			free (buff);
			free (buff_line);
			buff_line = NULL;
			return (NULL);
		}
		buff[red_byt] = '\0';
		buff_line = ft_strjoin2(buff_line, buff);
	}
	free (buff);
	return (buff_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff_line = help_get_next_line(fd, buff_line);
	if (!buff_line)
		return (NULL);
	line = get_line_of_text(buff_line);
	buff_line = save_next_line(buff_line);
	if (buff_line)
	{
		free (buff_line);
		buff_line = NULL;
	}
	return (line);
}

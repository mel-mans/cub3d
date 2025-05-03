/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:05:53 by acharik           #+#    #+#             */
/*   Updated: 2025/05/03 21:46:22 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parsing.h"

int	check_line2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

char	*ft_strjoin2(char *strr, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!strr && !buff)
		return (NULL);
	if (!strr)
		strr = ft_strdup("");
	str = malloc(sizeof(char) * ((ft_strlen(strr) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (strr)
		while (strr[++i] != '\0')
			str[i] = strr[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(strr) + ft_strlen(buff)] = '\0';
	if (strr)
		free(strr);
	return (str);
}

char	*ft_strdup(const char *string)
{
	size_t		i;
	char		*ptr;
	int			n;

	n = 0;
	i = ft_strlen(string);
	ptr = (char *)malloc(1 + i * sizeof(char));
	if (!ptr)
		return (NULL);
	while (string[n])
	{
		ptr[n] = string[n];
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = -1;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	ptr = malloc(1 + len * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[++i + start] && len > i)
	{
		ptr[i] = s[i + start];
	}
	ptr[i] = '\0';
	return (ptr);
}

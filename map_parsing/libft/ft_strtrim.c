/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:04:32 by acharik           #+#    #+#             */
/*   Updated: 2025/04/23 23:04:33 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/map_parsing.h"

static int	chec_in_set(char *ptr, char c)
{
	int	index;

	index = 0;
	while (ptr[index] != '\0')
	{
		if (c == ptr[index])
			return (1);
		index++;
	}
	return (0);
}

static char	*ft_strdup_n(char *src, int n)
{
	char	*ptr;
	int		i;

	i = 0;
	if (n < 0)
		n = 0;
	ptr = malloc((n + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	while (i < n)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*remove_from_beg_end(char *s1, char *set, char *ptr, int s_length)
{
	int	stop;
	int	stop1;
	int	index;
	int	l;

	stop = 1;
	stop1 = 1;
	index = 0;
	l = 0;
	while (s1[index] != '\0')
	{
		if (stop && chec_in_set(set, s1[index]))
			ptr++;
		else
			stop = 0;
		if (stop1 && chec_in_set(set, (char)s1[--s_length]))
			l++;
		else
			stop1 = 0;
		index++;
	}
	ptr = ft_strdup_n(ptr, ft_strlen(ptr) - l);
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s_length;
	char	*ptr;

	if (!s1)
		return (0);
	ptr = (char *)s1;
	s_length = ft_strlen((char *)s1);
	ptr = remove_from_beg_end((char *)s1, (char *)set, ptr, s_length);
	return (ptr);
}

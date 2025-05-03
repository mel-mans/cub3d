/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:04:01 by acharik           #+#    #+#             */
/*   Updated: 2025/05/03 17:56:22 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/map_parsing.h"
#include <stdio.h>

/* change one thing in this function the position of indext to start  */

static char	*ft_strcat_p(char *dest, const char *src, int position)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[i] != '\0' && position != 0)
		i++;
	while (src[len] != '\0')
	{
		dest[i] = src[len];
		i++;
		len++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		length;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(length);
	if (ptr == NULL)
		return (0);
	ft_strcat_p(ptr, s1, 0);
	ft_strcat_p(ptr, s2, 1);
	return (ptr);
}
/*
int	main(void)
{
  printf("%s",ft_strjoin("","alami"));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:04:25 by acharik           #+#    #+#             */
/*   Updated: 2025/04/23 23:04:26 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/map_parsing.h"
#include <stdio.h>
#include <string.h>

static int	chec_here(char *arr, char *find, size_t n)
{
	size_t	i;

	i = 0;
	while (find[i] != '\0')
	{
		if (find[i] != arr[i] || n == 0)
			return (0);
		i++;
		n--;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0 || *haystack == '\0')
		return (0);
	if (len == 1)
		len++;
	while (haystack[i] != '\0' && i < len - 1)
	{
		if (haystack[i] == needle[0])
		{
			if (chec_here(((char *)haystack + i), ((char *)needle), len - i))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
 // printf(" %s  %s",ft_strnstr ("abcdecdef","a",1),strnstr("abcdecdef","a",1));
   const char *s1 = "aaabcabcd";
	const char *s2 = "aabc";
	size_t max = strlen(s2);
	const char *i1;
	i1 = strnstr("abcdefhg", "", -1);
	const char *i2;
	i2 = ft_strnstr("abcdehg", "", -1);
  //
	printf("strn %s ft_str i2 %s %d", i1,i2,ft_strlen(""));
  return (0);
 }
*/

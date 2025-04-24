/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:03:40 by acharik           #+#    #+#             */
/*   Updated: 2025/04/23 23:03:41 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */






#include <stdlib.h>
#include <stdio.h>
#include "../includ/map_parsing.h"

void	*ft_calloc(size_t len, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	sum;

	i = 0;
	sum = len * size;
	ptr = malloc((len * size));
	if (ptr == NULL)
		return (0);
	while (sum)
	{
		ptr[i] = 0;
		sum--;
		i++;
	}
	return (ptr);
}
/*
int main()
{
	int *ptr = ft_calloc(5,4);
    printf(" %d ",ptr[5]);

}
*/

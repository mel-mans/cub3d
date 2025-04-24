/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:03:49 by acharik           #+#    #+#             */
/*   Updated: 2025/04/23 23:03:50 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../includ/map_parsing.h"
#include<unistd.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

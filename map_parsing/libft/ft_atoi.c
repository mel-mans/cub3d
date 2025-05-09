/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:02:39 by acharik           #+#    #+#             */
/*   Updated: 2025/04/23 23:03:12 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	index_fun(const char *nbr, int *s)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\v' || nbr[i] == '\n'
		|| nbr[i] == '\f' || nbr[i] == '\r')
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			(*s) *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nbr)
{
	int	i;
	int	nb;
	int	s;

	nb = 0;
	s = 1;
	i = index_fun(nbr, &s);
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		nb = nb * 10 + nbr[i] - '0';
		i++;
	}
	return (nb * s);
}

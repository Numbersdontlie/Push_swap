/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:02:13 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/21 13:21:25 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Function to convert string to integers to receive arguments
int	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == 32))
		nptr++;
	if ((*nptr == 43) || (*nptr == 45))
	{
		if (*nptr == 45)
			sign = -1;
		nptr++;
	}
	result = 0;
	while (((*nptr >= 48) && (*nptr <= 57)))
	{
		result = ((result * 10) + (*nptr - 48));
		nptr++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

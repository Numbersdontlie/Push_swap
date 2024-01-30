/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:02:13 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/30 01:08:08 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file utils.c
 * @brief Helper functions to operate during project
 * the functions help to: convert char to long, check
 * for digits, among others
 * 
 * @author Luis Perez (lperez-h)
**/

#include "push_swap.h"

//Function to convert string to integers to receive arguments
int	ft_atol(const char *nptr)
{
	int		sign;
	long	result;

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

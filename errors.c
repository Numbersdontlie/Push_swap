/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:34:49 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/29 14:06:55 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file erros.c
 * @brief check for possible errors in the arguments
 * the errors include: check for only numbers, check
 * for duplicates, check for overflow, check if
 * numbers are already sorted
 * 
 * @author Luis Perez (lperez-h)
**/

#include "push_swap.h"

int	ft_check_numbers(char *nbr)
{
	if (!(*nbr == '+' || *nbr == '-' || (*nbr >= '0' && *nbr <= '9')))
		return (1);
	if ((*nbr == '+' || *nbr == '-') && !(nbr[1] >= '0' && nbr[1] <= '9'))
		return (1);
	while (*nbr++)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (1);
	}
	return (0);
}

int	ft_check_sorted(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')//iterate in list before reaching the end of list
	{
		if (argv[i] > argv[i + 1])//check if next value is lower than previous
			return (0);
		i++;
	}
	return (1);
}


int	ft_check_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != '\0')//to iterate the list
	{
		j = 2;
		while (argv[j] != '\0')//iterate through the args
		{
			if(argv[i] == argv[j])//compare tmp value with value of node that come after it
				return (1);
			j++;//step of iteration for num compare
		}
		i++;
	}
	return (0);//return 0 if no duplicates where found
}

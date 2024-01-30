/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:34:49 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/30 18:42:42 by lperez-h         ###   ########.fr       */
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
	if (!(*nbr == '+' || *nbr == '-' || (*nbr >= '0' && *nbr <= '9')))//check for sign or digit 
		return (1);
	if ((*nbr == '+' || *nbr == '-') && !(nbr[1] >= '0' && nbr[1] <= '9'))//check for digit after sign
		return (1);
	while (*nbr++)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))//check for the rest of characters in string
			return (1);
	}
	return (0);//is a valid integer
}

//Function to check if the list is already sorted
int	ft_check_sorted(t_node *stack)
{
	t_node	*tmp;//counter

	tmp = stack;//init at head
	while (tmp != NULL)//iterate in list
	{
		if (tmp->value > tmp->next->value)//check if next value is lower than previous
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_duplicates(t_node *head)
{
	t_node	*tmp;//node to iterate
	t_node	*num;//node to compare number

	if (head == NULL)//check for empty list
		return (0);
	tmp = head;//init at head
	while (tmp != NULL)//to iterate the list
	{
		num = tmp->next;//init at next node
		while (num != NULL)//iterate through the list
		{
			if(tmp->value == num->value)//compare tmp value with value of node that come after it
				return (1);
			num = num->next;//step of iteration for num compare
		}
		tmp = tmp->next;//step of iteration for tmp
	}
	return (0);//return 0 if no duplicates where found
}
/*
int	ft_check_sorted(t_node **stack)
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
}*/
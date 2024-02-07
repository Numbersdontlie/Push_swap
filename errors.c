/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:34:49 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/07 12:07:28 by lperez-h         ###   ########.fr       */
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

int	ft_check_numbers(char **argv)
{
	int	i;

	i = 1;
	if (!(argv[i] == '+' || argv[i] == '-' || (argv[i] >= '0' && argv[i] <= '9')))//check for sign or digit 
		return (1);
	if ((argv[i] == '+' || argv[i] == '-') && !(argv[i][1] >= '0' && argv[i][1] <= '9'))//check for digit after sign
		return (1);
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))//check for the rest of characters in string
			return (1);
		i++;
	}
	return (0);//is a valid integer
}

int	ft_check_sorted(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])//iterate in list before reaching the end of list
	{
		if (argv[i] > argv[i + 1])//check if next value is lower than previous
			return (0);//is not sorted
		i++;
	}
	return (1);//is already sorted
}

int	ft_check_duplicates(char **argv)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 0;
	i = 1;
	while (argv[i])//to iterate the list
	{
		j = 2;
		while (argv[j])//iterate through the args
		{
			num1 = ft_atol(argv[i]);
			num2 = ft_atol(argv[j]);
			if(num1 == num2)//compare tmp value with value of node that come after it
				return (1);//there are duplicates
			j++;//step of iteration for num compare
		}
		i++;
	}
	return (0);//return 0 if no duplicates where found
}

void	ft_error_handle(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/*
//Function to check if the list is already sorted
int	ft_check_sorted(t_node *stack)
{
	t_node	*tmp;//counter

	tmp = stack;//init at head
	while (tmp != NULL)//iterate in list
	{
		if (tmp->value > tmp->next->value)//check if next value is lower than previous
			return (0);//not sorted
		tmp = tmp->next;
	}
	return (1);//is sorted
}

int	ft_check_duplicates(t_node *head, int num)
{
	t_node	*tmp;//node to iterate

	if (head == NULL)//check for empty list
		return (0);
	tmp = head;//init at head
	while (tmp != NULL)//iterate the list
	{
		if(tmp->value == num)//compare tmp value with value of num
			return (1);//is repeated
		tmp = tmp->next;//step of iteration for tmp
	}
	return (0);//no duplicates
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:34:49 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/08 14:13:29 by lperez-h         ###   ########.fr       */
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

//Function to check if the list is already sorted
int	ft_check_sorted(t_node *stack)
{
	t_node	*tmp;//counter

	tmp = stack;//init at head
	while (tmp->next != NULL)//iterate in list
	{
		if (tmp->value > tmp->next->value)//check if next value is lower than previous
			return (0);//not sorted
		tmp = tmp->next;
	}
	return (1);//is sorted
}

void	ft_check_duplicates(char **argv)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 0;
	i = 1;
	if (!argv[1])
		ft_error_handle();
	while (argv[i])//to iterate the list
	{
		num1 = ft_atol(argv[i]);
		j = i + 1;
		while (argv[j])//iterate through the args
		{
			num2 = ft_atol(argv[j]);
			if(num1 == num2)//compare tmp value with value of node that come after it
				ft_error_handle();;//there are duplicates
			j++;//step of iteration for num compare
		}
		i++;
	}
}

void	ft_error_handle(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/*
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
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);//is already sorted
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
}


int	ft_check_numbers(char **argv)
{
	int	i;

	i = 1;
	if (!(*argv[i] == '+' || *argv[i] == '-' || (*argv[i] >= '0' && *argv[i] <= '9')))//check for sign or digit 
		ft_error_handle();
	if ((*argv[i] == '+' || *argv[i] == '-') && !(argv[i][1] >= '0' && argv[i][1] <= '9'))//check for digit after sign
		ft_error_handle();
	while (argv[i])
	{
		if (!(*argv[i] >= '0' && *argv[i] <= '9'))//check for the rest of characters in string
			ft_error_handle();
		i++;
	}
	return (0);//is a valid integer
}
*/
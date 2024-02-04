/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:05:29 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/04 23:32:30 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file utils_stack.c
 * @brief Helper functions to operate with stacks
 * the functions in this file help to
 * operate the stacks: deallocate memory, size measure
 * among others
 * 
 * @author Luis Perez (lperez-h)
**/

#include "push_swap.h"

//Function to deallocate the list
void	ft_stack_dealloc(t_node **stack)
{
	t_node	*tmp;//counter
	t_node	*aux;

	if (stack == NULL)//check if list is empty already
		return ;
	while (tmp->next != NULL)//iterate until last element of list
	{
		aux = *stack;
		tmp = (*stack)->next;//init at head
		free(aux);//free the previous node
	}
	*stack = NULL;//set head(stack) to null
}

//Function to measure the size of the stack
int	ft_stack_size(t_node **stack)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

//Function to check which algorithm to use based on stack size
void	router(t_node *stack)
{
	int	len;

	len = ft_stack_size(&stack);
	if (len <= 3)
		ft_sort_stack_3(stack);//ToDo. Also check if stack_size = 2 inside this function
	else if (len >= 4)
		ft_sort_stack_5(stack);//ToDo. Should check for size 4?
	else if (len > 10)
		ft_sort_stack_big(stack);//ToDo
}
//Function to calculate the average in the program
int	ft_average(t_node *stack)
{
	t_node	*tmp;
	long	sum;
	int		n;
	int		avg;

	tmp = stack;
	sum = 0;
	n = ft_stack_size(&stack);
	while (tmp->next != NULL)
	{
		sum += tmp->value;
		tmp = tmp->next;
	}
	avg = sum / n;
	return (avg);
}

//Function to check if the value is above or below the avg
void	ft_above_avg(t_node *stack)
{
	t_node	*tmp;
	double	avg;

	tmp = stack;
	avg = ft_average(&stack);
	while (tmp->next != NULL)
	{
		if (tmp->value > avg)
			tmp->above_avg = true;
		else
			tmp->above_avg = false;
		tmp = tmp->next;
	}
}

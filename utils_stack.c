/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:05:29 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/13 15:52:45 by lperez-h         ###   ########.fr       */
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
	t_node	*aux;

	if (stack == NULL)//check if list is empty already
		return ;
	while (*stack)//iterate until last element of list
	{
		aux = (*stack)->next;;//save node
		free(*stack);
		*stack = aux;
	}
	*stack = NULL;//set head(stack) to null
}

//Function to measure the size of the stack
int	ft_stack_size(t_node *stack)
{
	int		count;

	count = 0;
	while (stack->next != NULL && stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
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
	n = ft_stack_size(stack);
	if (n == 0)//case when list is empty, avoid to divide by zero
		return (1);
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
	double	avg;

	avg = ft_average(stack);
	while (stack)
	{
		if (stack->value > avg)
			stack->above_avg = true;
		else
			stack->above_avg = false;
		stack = stack->next;
	}
}

//Function to assign a index to each number in my list
void	ft_get_index(t_node *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return ;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}
/*
void	ft_router(t_node *stack_a, t_node *stack_b)
{
	int	len;

	len = ft_stack_size(stack_a);
	if (len <= 3)
		ft_sort_stack_3(&stack_a);//ToDo. Also check if stack_size = 2 inside this function
	else if (len > 4)
		ft_sort_stack_5(&stack_a, &stack_b);//ToDo. Should check for size 4?
	else if (len > 5)
		ft_sort_stack_big(&stack_a, &stack_b);//ToDo
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:05:29 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/19 00:10:48 by lperez-h         ###   ########.fr       */
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
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

//Function to calculate the average in the program
int	ft_average(t_node *stack)
{
	long	sum;
	int		n;

	sum = 0;
	n = ft_stack_size(stack);
	//if (n == 0)//case when list is empty, avoid to divide by zero
	//	return (1);
	while (stack)
	{
		sum = sum + stack->value;
		stack = stack->next;
	}
	return (sum / n);
}

void	ft_set_objetivo(t_node *stack_a, t_node *stack_b)
{
	t_node	*objetivo;
	t_node	*tmp;
	int		mejor;

	while(stack_b)
	{
		mejor = INT_MAX;
		tmp = stack_a;
		while (tmp)
		{
			if (tmp->value > stack_b->value && tmp->value < mejor)
			{
				mejor = tmp->value;
				objetivo = tmp;
			}
			tmp = tmp->next;
		}
		if (mejor == INT_MAX)
			stack_b->target_node = ft_find_low(stack_a);
		else
			stack_b->target_node = objetivo;
		stack_b = stack_b->next;
	}
}

void	ft_recalculate_numbers(t_node *stack_a, t_node *stack_b)
{
	ft_set_objetivo(stack_a, stack_b);
	ft_set_senal(stack_a);
	ft_set_senal(stack_b);
	ft_calculate_price(stack_a, stack_b);
}

/*
Function to assign a index to each number in my list
void	ft_get_index(t_node *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return ;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
}

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
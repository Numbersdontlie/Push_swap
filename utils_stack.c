/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:05:29 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/03 00:44:23 by luifer           ###   ########.fr       */
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

t_node	ft_last_node(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp != NULL)
		tmp = tmp->next;
	return (*tmp);
}

t_node	ft_create_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->value = num;
	node->next = NULL;
	return (*node);
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

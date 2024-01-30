/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:05:29 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/30 20:59:58 by lperez-h         ###   ########.fr       */
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
void	ft_stack_dealloc(t_node **head)
{
	t_node	*tmp;//counter

	if (head == NULL)//check if list is empty already
		return ;
	tmp = *head;//init at head
	while (tmp->next != NULL)//iterate until last element of list
	{
		tmp = tmp->next;//move 1 step forward
		free(tmp->prev);//free the previous node
	}
	free(tmp);//free the last element of the list
	*head = NULL;//set head(stack) to null
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

t_node	ft_last_node(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
		tmp = tmp->next;
	return (*tmp);
}

//Function to check which algorithm to use based on stack size
void	router(t_node *head)
{
	int	len;

	len = ft_stack_size(&head);
	if (len <= 3)
		ft_sort_stack_3(head);//ToDo. Also check if stack_size = 2 inside this function
	else if (len >= 4)
		ft_sort_stack_5(head);//ToDo. Should check for size 4?
	else if (len > 10)
		ft_sort_stack_big(head);//ToDo
}

t_node	ft_find_high(t_node *stack)
{
	t_node	*tmp;
	t_node	*high_node;
	int		high;

	tmp = stack;
	high = 0;
	while (tmp->next != NULL)
	{
		if (tmp->value > high)
		{
			high = tmp->value;
			high_node = tmp;
		}
		tmp = tmp->next;
	}
	return (*high_node);
}

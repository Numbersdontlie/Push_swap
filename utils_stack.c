/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:05:29 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/21 16:00:18 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*	@file utils_stack.c
*	@brief Helper functions to operate with stacks
*	the functions in this file help to
*	operate the stacks: deallocate memory, size measure
*	among others
*
*	@author Luis Perez (lperez-h)
**/

#include "push_swap.h"

//Function to deallocate the list
void	ft_stack_dealloc(t_node **head, t_node **tail)
{
	t_node	*tmp;//counter

	if (tail == NULL)//check if list is empty already
		return ;
	tmp = *head;//init at head
	while (tmp->next != NULL)//iterate until last element of list
	{
		tmp = tmp->next;//move 1 step forward
		free(tmp->prev);//free the previous node
	}
	free(tmp);//free the last element of the list
	*head = NULL;//set head to null
	*tail = NULL;//set tail to null
}

//Function to measure the size of the stack
int	ft_stack_size(t_node **head)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = head;
	while (tmp->next != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:05:29 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/24 14:27:31 by lperez-h         ###   ########.fr       */
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
	tmp = *head;
	while (tmp->next != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

//Function to check which algorithm to use based on stack size
void	router(t_node **head)
{
	int	len;

	len = ft_stack_size(&head);
	if (len <= 3)
		ft_sort_stack_3(&head);//ToDo. Also check if stack_size = 2 inside this function
	else if (len >= 4)
		ft_sort_stack_5(&head);//ToDo. Should check for size 4?
	else if (len > 10)
		ft_sort_stack_big(&head);//ToDo
}

//Function to index the initial array 
void	ft_index(t_node **head)
{
	int	i;
	t_node	*tmp;
	
	i = 0;
	tmp = head;
	
}

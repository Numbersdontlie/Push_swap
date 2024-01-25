/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/25 19:00:10 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_stack.c
 * @brief Create and initialize the stacks
 * the functions in this file have the purpose
 * of initialize empty list, insert data to it
 * and check the parameters quality.
 * 
 * @author Luis Perez (lperez-h)
**/

# include "push_swap.h"
# include <stdio.h>

void	ft_insert_data(t_node **head, t_node **tail, int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)//check fail of allocation
		exit (EXIT_FAILURE);
	if (*head == NULL)//check if stack is empty to define name of the stack and how to pass it
	{
		node->value = num;
		node->prev = NULL;
		node->next = NULL;
		*tail = node;
		*head = node;
	}
	else
	{
		node->value = num;//assign value to node
		node->prev = *tail;//assign prev to node
		node->next = NULL;//assign next to nullvoid  print_stack(t_node *root)
		(*tail)->next = node;//assign next to the previous tail
		*tail = node;//assign new tail (the node created)
	}
}

int	ft_check_numbers(t_node **head)
{
	t_node	*tmp;//counter

	tmp = *head;//initialize at head
	while (tmp != NULL)//iterate through the list
	{
		if (sizeof(tmp->value) != sizeof(int))//check for only integers in list
			return (1);
		else if(tmp->value < INT_MIN || tmp->value > INT_MAX)//check if bigger than int 
			return (1);
		tmp = tmp->next;//step of iteration
	}
	return (0);
}

int	ft_check_sorted(t_node **head)
{
	t_node	*tmp;//counter

	tmp = *head;//init at head
	while (tmp != NULL && tmp->next != NULL)//iterate in list before reaching the end of list
	{
		if (tmp->value > tmp->next->value)//check if next value is lower than previous
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_duplicates(t_node **head)
{
	t_node	*tmp;//node to iterate
	t_node	*num;//node to compare number

	if (head == NULL)//check for empty list
		return (0);
	tmp = *head;//init at head
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
//Still missing the negative number handle
t_node	*ft_stack_a_init(char **argv)
{
	t_node	*head;
	t_node	*tail;
	int		i;
	long	num;
 
	i = 1;
	head = NULL;
	tail = NULL;
	while(argv[i])
	{
		num = ft_atol(argv[i]);
		ft_insert_data(&head, &tail, num);
		i++;
		num = 0;
	}
	//print_stack(head);
	if (ft_check_duplicates(&head) == 1 || ft_check_numbers(&head) == 1 || ft_check_sorted(&head) == 1)
	{
		ft_stack_dealloc(&head, &tail);
		exit (EXIT_FAILURE);
	}
	return (head);
}

t_node	ft_stack_b_init(t_node **stack_a)
{
	t_node	*head;
	t_node	*tail;
	int	i;
	int	n;

	i = 0;
	n = ft_stack_size(stack_a);
	while (i < n - 3)
	{
		ft_insert_data(&head, &tail, 0);
		i++;
	}
	return (*head);
}

void  print_stack(t_node *root)
{
    while (root != NULL)
    {
//      ft_printf("node->current_position: %d\n", root->index);
        printf("node->data: %d\n", root -> value);
//      ft_printf("node->prev: %p\n", (void *)root -> prev);
//      ft_printf("node->next: %p\n\n", (void *)root -> next);
        root = root -> next;
    }
}
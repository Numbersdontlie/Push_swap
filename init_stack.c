/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/29 14:19:03 by lperez-h         ###   ########.fr       */
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

void	ft_insert_data(t_node **head, int num)
{
	t_node	*node;
	t_node	**tail;

	node = malloc(sizeof(t_node));
	if (node == NULL)//check fail of allocation
		exit (EXIT_FAILURE);
	if (*head == NULL)//check if stack is empty to define name of the stack and how to pass it
	{
		node->value = num;
		node->prev = NULL;
		node->next = NULL;
		*head = node;
		*tail = node;
	}
	else
	{
		node->value = num;//assign value to node
		**tail = ft_last_node(&head);
		node->prev = *tail;//assign prev to node
		node->next = NULL;//assign next to null
		(*tail)->next = node;//assign next to the previous tail
		*tail = node;//assign new tail (the node created)
	}
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
		ft_insert_data(&head, num);
		i++;
	}
	//print_stack(head);
	if (ft_check_duplicates(&head) == 1 || ft_check_numbers(&head) == 1 || ft_check_sorted(&head) == 1)
	{
		ft_stack_dealloc(&head, &tail);
		write(1, "Error\n", 6);
	}
	return (head);
}

t_node	ft_stack_b_init(t_node **stack_a)
{
	t_node	*head;
	//t_node	*tail;
	int	i;
	int	n;

	i = 0;
	n = ft_stack_size(stack_a);
	while (i < n - 3)
	{
		ft_insert_data(&head, 0);
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
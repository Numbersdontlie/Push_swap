/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/30 01:07:53 by luifer           ###   ########.fr       */
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

void	ft_insert_data(t_node **stack, int num)
{
	t_node	*node;
	t_node	*head;
	t_node	*tail;

	node = malloc(sizeof(t_node));
	if (node == NULL)//check fail of allocation
		exit (EXIT_FAILURE);
	if (*stack == NULL)//check if stack is empty to define name of the stack and how to pass it
	{
		node->value = num;
		node->prev = NULL;
		node->next = NULL;
		head = node;
		tail = node;
	}
	else
	{
		node->value = num;//assign value to node
		tail = ft_last_node(&head);//find the tail
		node->prev = tail;//assign tail as prev to node
		node->next = NULL;//assign next as null, since is the new tail
		tail->next = node;//assign next to the previous tail
		tail = node;//assign new tail (the node created)
	}
}

void	*ft_stack_a_init(t_node **stack_a, char **argv)
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
		if (ft_check_numbers(argv[i]) == 1)
			return ("Error\n");
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			write(2, "Error\n", 6);
		//Insert value into list
		ft_insert_data(&stack_a, num);
		//check for duplicates in list
		if (ft_check_duplicates(&stack_a) == 1)
		{
			ft_stack_dealloc(&stack_a);
			write(2, "Error\n", 6);
		}
		//check for sort numbers in list
		if (ft_check_sorted(&stack_a) == 1)
		{
			ft_stack_dealloc(&stack_a);
			write(2, "Error\n", 6);
		}
		i++;
	}
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
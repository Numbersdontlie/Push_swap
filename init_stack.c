/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/31 11:30:10 by luifer           ###   ########.fr       */
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

	tail = NULL;
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
		*tail = ft_last_node(*stack);//find the tail
		node->prev = tail;//assign tail as prev to node
		node->next = NULL;//assign next as null, since is the new tail
		tail->next = node;//assign next to the previous tail
		tail = node;//assign new tail (the node created)
	}
}

void	ft_stack_a_init(t_node **stack_a, char **argv)
{
	int		i;
	long	num;
 
	i = 1;
	while(argv[i])
	{
		if (ft_check_numbers(&argv[i]) == 1)//check for numbers
			return ;
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)//check for overflow
			write(2, "Error\n", 6);
		if (ft_check_duplicates(stack_a, num) == 1)//check for duplicates
		{
			ft_stack_dealloc(stack_a);
			write(2, "Error\n", 6);
		}
		if (ft_check_sorted(stack_a) == 1)//check if stack is already sorted
		{
			ft_stack_dealloc(stack_a);
			write(2, "Error\n", 6);
		}
		ft_insert_data(stack_a, num);//insert after all the check are ok
		i++;
	}
}

void	ft_stack_b_init(t_node **stack_a)
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
	//return (*head);
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
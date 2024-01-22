/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/22 16:09:33 by lperez-h         ###   ########.fr       */
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

//Function to initialize a single 
/*void	ft_node_init(t_node **head, t_node **tail, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		exit (EXIT_FAILURE);
		return ;
	}
	new_node->value = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	*tail = new_node;
	*head = new_node;
}*/

//Function to put data into the stack A, it will add at the end of the list
void	ft_insert_data(t_node **head, t_node **tail, int num)
{
	t_node	*node;
	t_node	*new_node;

	node = malloc(sizeof(t_node));
	if (node == NULL)//check fail of allocation
		exit (EXIT_FAILURE);
	if (*head == NULL)//check if stack is empty to define name of the stack and how to pass it
	{
		new_node = malloc(sizeof(t_node));
		if (new_node == NULL)
		{
			exit (EXIT_FAILURE);
			return ;
		}
		new_node->value = num;
		new_node->prev = NULL;
		new_node->next = NULL;
		*tail = new_node;
		*head = new_node;
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

//Function to check args: reciving numbers? 
int	ft_check_numbers(t_node **head)
{
	t_node	*tmp;//counter

	tmp = *head;//initialize at head
	while (tmp != NULL)//iterate through the list
	{
		if (ft_isdigit(tmp->value) == 0)//check for only numbers in list
			return (1);
		else if(tmp->value < INT_MIN || tmp->value > INT_MAX)//check if bigger than int 
			return (1);
		tmp = tmp->next;//step of iteration
	}
	return (0);
}

//Function to check if the list is already sorted
int	ft_check_sorted(t_node **head)
{
	t_node	*tmp;//counter

	tmp = *head;//init at head
	while (tmp != NULL)//iterate in list
	{
		if (tmp->value > tmp->next->value)//check if next value is lower than previous
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

//Function to check if there are dupliprintf("%d\n", curr->value)cate in the list
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

t_node	*ft_stack_a_init(char **argv)
{
	t_node	*head;
	t_node	*tail;
	int		i;
 
	i = 1;
	head = NULL;
	tail = NULL;
	while(argv[i])
	{
		ft_insert_data(&head, &tail, ft_atol(argv[i]));
		i++;
	}
	print_stack(head);
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
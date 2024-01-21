/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/21 01:23:02 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//Function to initialize an empty list with head and tail null
void	ft_initialize_list(t_node **head, t_node **tail)
{
	*head = NULL;
	*tail = NULL;
}

//Function to put data into the stack A, it will add at the end of the list
void	ft_insert_data(t_node **head, t_node **tail, int num)
{
	t_node	*node;
	t_node	*aux;

	node = malloc(sizeof(t_node));
	if (node == NULL)//check fail of allocation
		return (1);
	if (*head == NULL)//check if stack is empty to define name of the stack and how to pass it
	{
		*head = node;
		*tail = node;
		node->prev = NULL;
		node->next = NULL;
		return ;
	}
	node->value = num;//assign value to node
	node->prev = *tail;//assign prev to node
	node->next = NULL;//assign next to node
	(*tail)->next = node;//assign next to the previous tail
	*tail = node;//assign new tail (the node created)
}

//Function to check args: reciving numbers? already sorted? are repeated nums?
//Deallocate stack if needed
int	ft_check_numbers(t_node **head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (ft_isdigit(tmp->value) == 0)
		{
			//free the stack
			//Exit with error
		}
		tmp = tmp->next;
	}

}

int	ft_check_sorted(t_node **head)
{

}

//Function to deallocate the stack
void	stack_dealloc(t_node)
{

}


void	ft_parser(char *s)
{
	//Loop
		//check for sign of each argument
		//check if the arguments are digits 
		//convert from string to number and save it
		//check for MAX_INT and MIN_INT
		//Add the value to the stack A
	//Once the stack is populated check for duplicates
	//Return something
}

//VALIDATOR//
/*
Create a function to validate the args passed
as arguments. If there's an error:
-free the stacks
-show error message
-return
*/
int	is_valid(int argc, char **argv)
{
	int	i;
	long *tmp;

	i = 1;
	while (i <= argc)
	{
		
	}
}

//IS SORTED?//
/*
write a function to check if stack a is sorted
*/

//ROUTING?//
/*
Create a router function to pick algorithm 
based on the number of args
*/

#include "push_swap.h"

void	stack_init(t_node **stack_a, int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	while(argv[i])
	{
		if (ft_check_numbers(argc, argv) != 0)//ToDo
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit(1);
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit(1);
		}
		ft_fill_stack(stack_a, num);//ToDo
		i++;
	}
}
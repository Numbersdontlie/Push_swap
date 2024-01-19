/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/19 02:13:10 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//Function to convert string to integers to receive arguments - can I make it long? what need to change?
int	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == 32))
		nptr++;
	if ((*nptr == 43) || (*nptr == 45))
	{
		if (*nptr == 45)
			sign = -1;
		nptr++;
	}
	result = 0;
	while (((*nptr >= 48) && (*nptr <= 57)))
	{
		result = ((result * 10) + (*nptr - 48));
		nptr++;
	}
	return (result * sign);
}

void	ft_new_node(t_node **tail, t_node **head, int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->value = num;
	new->prev = NULL;
	new->next = NULL;
	*tail = new;
	*head = new;
}

//Function to put data into the stack A
void	ft_insert_data(t_node *tail, int num)
{
	t_node	*tail;
	t_node	*head;
	t_node	*node;
	t_node	*aux;

	tail = NULL;
	head = NULL;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (1);
	node->value = num;
	node->prev = NULL;
	node->next = *tail;
	if (*stack_a == NULL)
		node = ft_new_node(&stack_a, num);//check parameters
	
	
	

}

/*t_stack	*ft_newnode(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->has_i = false;
	new_node->next = NULL;
	return (new_node);
}*/

//Function to deallocate the stack
void	stack_dealloc(t_node)
{

}

//Function to check args: reciving numbers? already sorted? are repeated nums?
//Deallocate stack if needed
int	stack_checker(t_node)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/21 13:21:19 by lperez-h         ###   ########.fr       */
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
int	ft_check_numbers(t_node **head, t_node **tail)
{
	t_node	*tmp;//counter

	tmp = head;//initialize at head
	while (tmp != NULL)//iterate through the list
	{
		if (ft_isdigit(tmp->value) == 0)//check for only numbers in list
		{
			ft_stack_dealloc(&head, &tail);//dealocate if needed
			exit("Error\n");//exit with error 
		}
		else if(tmp->value < INT_MIN || tmp->value > INT_MAX)//check if bigger than int 
		{
			ft_stack_dealloc(&head, &tail);//deallocate if needed
			exit("Error\n");//exit with error status
		}
		tmp = tmp->next;//step of iteration
	}
	return (0);
}

//Function to check if the list is already sorted
int	ft_check_sorted(t_node **head, t_node **tail)
{
	t_node	*tmp;//counter

	tmp = head;//init at head
	while (tmp != NULL)//iterate in list
	{
		if (tmp->value > tmp->next->value)//check if next value is lower than previous
		{
			ft_stack_dealloc(&head, &tail);//deallocate if needed
			exit("Error\n");
		}
		tmp = tmp->next;
	}
	return (0);
}

//Function to check if there are duplicate in the list
int	ft_check_duplicates(t_node **head, t_node **tail)
{
	t_node	*tmp;//node to iterate
	t_node	*num;//node to compare number

	if (head == NULL)//check for empty list
		return (0);
	tmp = head;//init at head
	while (tmp != NULL)//to iterate the list
	{
		num = tmp->next;//init at next node
		while (num != NULL)//iterate through the list
		{
			if(tmp->value == num->value)//compare tmp value with value of node that come after it
			{
				ft_stack_dealloc(&head, &tail);//deallocate if needed
				exit("Error\n");//exit with error
			}
			num = num->next;//step of iteration for num compare
		}
		tmp = tmp->next;//step of iteration for tmp
	}
	return (0);//return 0 if no duplicates where found
}

t_node	stack_init(t_node **stack_a, int argc, char **argv)
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
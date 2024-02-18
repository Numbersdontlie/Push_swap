/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:43:10 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/19 00:31:12 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_nodes.c
 * @brief Works with the nodes and calculate info that will needed
 * during the project: min, max, mid
 * 
 * 
 * @author Luis Perez (lperez-h)
**/

# include "push_swap.h"

t_node	*ft_find_high(t_node *stack)
{
	t_node	*high_node;
	int		high;

	high = INT_MIN;//secure init and assign value
	while (stack)//iterate in stack
	{
		if (stack->value > high)
		{
			high = stack->value;//takes the new high 
			high_node = stack;//save the node with the value
		}
		stack = stack->next;//step of iteration
	}
	return (high_node);//return node with the highest value
}

t_node	*ft_find_low(t_node *stack)
{
	t_node	*low_node;
	int		low;

	low = INT_MAX;//secure init and assign of value at 1st iteration
	while (stack)//iterate through stack
	{
		if (stack->value < low)
		{
			low = stack->value;
			low_node = stack;
		}
		stack = stack->next;
	}
	return (low_node);
}

t_node	*ft_last_node(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
		stack = stack->next;
	return (stack);
}

t_node	*ft_create_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = num;
	node->next = NULL;
	return (node);
}

void	ft_add_back(t_node	**stack_a, t_node *node)
{
	t_node	*tmp;

	if (stack_a == NULL || node == NULL)
		return ;
	if (*stack_a == NULL)
	{
		*stack_a = node;
		return ;
	}
	tmp = *stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

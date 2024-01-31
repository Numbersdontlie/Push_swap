/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:43:10 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/31 11:30:12 by luifer           ###   ########.fr       */
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

//Function to find the node with highest value in my list
t_node	ft_find_high(t_node *stack)
{
	t_node	*tmp;
	t_node	*high_node;
	int		high;

	tmp = stack;
	high = 0;
	while (tmp->next != NULL)
	{
		if (tmp->value > high)
		{
			high = tmp->value;
			high_node = tmp;
		}
		tmp = tmp->next;
	}
	return (*high_node);
}

//Function to find the node with lowest value in my list
t_node	ft_find_low(t_node *stack)
{
	t_node	*tmp;
	t_node	*low_node;
	int		low;

	tmp = stack;
	low = 0;
	while (tmp != NULL)
	{
		if (tmp->value < low)
		{
			low = tmp->value;
			low_node = tmp->value;
		}
		tmp = tmp->next;
	}
	return (*low_node);
}

//Function to calculate the midle point in the list
int	ft_mid_node(t_node **head)
{

}

//Add node to the head

//Add node to the tail

//check duplicates 

//create nodes

//delete nodes

//last node

//list size

//print node

//node details
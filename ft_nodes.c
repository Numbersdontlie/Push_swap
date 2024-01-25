/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:43:10 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/25 23:14:03 by luifer           ###   ########.fr       */
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

//Function to find the max value in my list
t_node	ft_max_node(t_node **head)
{
	t_node	*tmp;//Node declare iterate
	t_node	*aux;
	int		max;//int compare declare
	int		pos;//int to get position

	tmp = head;//
	max = tmp->value;//start for the 1st element of the list
	pos = 0;
	while (tmp != NULL)//iterate through the list
	{
		if (max > tmp->value)//if current value is greather than previous max
		{	
			max = tmp->value;//assign max the new higher
			pos = tmp->list_idex;//keep the idx position when unsorted
			aux = tmp;
		}
		tmp = tmp->next;//step of iteration
	}
	return (*aux);
}

t_node	ft_min_node(t_node **head)
{
	t_node	*tmp;
	t_node	*aux;
	int		min;
	int		pos;

	tmp = head;
	min = tmp->value;
	pos = 0;
	while (tmp != NULL)
	{
		if (min < tmp->value)
		{
			min = tmp->value;
			pos = tmp->list_idex;
			aux = tmp;
		}
		tmp = tmp->next;
	}
	return (*aux);
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
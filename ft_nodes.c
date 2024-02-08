/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:43:10 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/08 14:30:36 by lperez-h         ###   ########.fr       */
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
	return (high_node);
}

t_node	*ft_find_low(t_node *stack)
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
			low_node = tmp;
		}
		tmp = tmp->next;
	}
	return (low_node);
}

t_node	ft_last_node(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp != NULL)
		tmp = tmp->next;
	return (*tmp);
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

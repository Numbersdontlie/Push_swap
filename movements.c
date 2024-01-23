/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:51:39 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/23 19:23:18 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file movements.c
 * @brief implement the allowed movements to sort
 * the stack. The movements are: swap, reverse,
 * rotate and push. 
 * 
 * @author Luis Perez (lperez-h)
**/

# include "push_swap.h"

//SWAP -> sa = stack_a, sb = stack_b, ss = stack_a + stack_b
void	ft_swap(t_node **head)
{
	t_node	*tmp;

	tmp = (*head)->next;
	(*head)->prev = tmp;
	(*head)->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = head;
	head = tmp;
	//free(tmp)?;
	//check for edge cases
}

//ROTATE -> ra, rb, rr
void	ft_rotate(t_node **head, t_node **tail)
{
	t_node *tmp;

	tmp = (*head)->next;
	(*head)->prev = tail;
	(*head)->next = NULL;
	tmp->prev = NULL;
	(*tail)->next = head;
	tail = head;
	head = (*head)->next;
	//free(tmp)?;
	//check for edge cases
}

//REVERSE ROTATE -> rra, rrb, rrr
void	ft_reverse_rotate(t_node **head, t_node **tail)
{
	t_node	*tmp;

	tmp = (*tail)->prev;
	(*tail)->prev = NULL;
	(*tail)->next = head;
	tmp->next = NULL;
	(*head)->prev = tail;
	head = tail;
	tail = (*tail)->prev;
	//free(tmp)?;
	//check for edge cases
}

//PUSH -> pa, pb
void	ft_push_a(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	tmp = (*head_b)->next;
	(*head_a)->prev = head_b;
	(*head_b)->prev = NULL;
	(*head_b)->next = head_a;
	tmp->prev = NULL;
	head_a = head_b;
	head_b = (*head_b)->next;
	//check for edge cases
}

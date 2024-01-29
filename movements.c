/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:51:39 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/29 12:57:15 by lperez-h         ###   ########.fr       */
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
	if (*head == NULL || ft_stack_size(&head) == 1)//check for empty or just one element in list
		return ;
	//free(tmp)?;
}
//To swap both stacks use the t_stacks structure

//ROTATE -> ra, rb, rr
void	ft_rotate(t_node **head, t_node **tail)
{
	t_node *tmp;

	if (ft_stack_size(&head) > 3)
	{
		tmp = (*head)->next;
		(*head)->prev = tail;
		(*head)->next = NULL;
		tmp->prev = NULL;
		(*tail)->next = head;
		tail = head;
		head = (*head)->next;
	}
	else
		return ;
	//free(tmp)?;
}
//To rotate both stacks use the t_stacks structure

//REVERSE ROTATE -> rra, rrb, rrr
void	ft_reverse_rotate(t_node **head, t_node **tail)
{
	t_node	*tmp;

	if (ft_stack_size(&head) > 3)
	{
		tmp = (*tail)->prev;
		(*tail)->prev = NULL;
		(*tail)->next = head;
		tmp->next = NULL;
		(*head)->prev = tail;
		head = tail;
		tail = (*tail)->prev;
	}
	else
		return ;
	//free(tmp)?;
}
//To reverse both stacks use the t_stacks structure

//PUSH -> pa, pb
void	ft_push(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (stack_b != NULL)
	{
		tmp = (*stack_b)->next;
		(*stack_a)->prev = stack_b;
		(*stack_b)->prev = NULL;
		(*stack_b)->next = stack_a;
		tmp->prev = NULL;
		stack_a = stack_b;
		stack_b = (*stack_b)->next;
	}
	else 
		return ;
	//check for edge cases
}

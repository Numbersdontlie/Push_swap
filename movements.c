/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:51:39 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/30 17:49:32 by lperez-h         ###   ########.fr       */
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
void	ft_swap(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack)->next;
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = *stack;
	stack = &tmp;
	if (*stack == NULL || ft_stack_size(stack) == 1)//check for empty or just one element in list
		return ;
	//free(tmp)?;
}
//To swap both stacks use the t_stacks structure

//ROTATE -> ra, rb, rr
void	ft_rotate(t_node **stack)
{
	t_node *tmp;
	t_node	*tail;

	tail = NULL;
	if (ft_stack_size(stack) > 3)
	{
		tmp = (*stack)->next;
		*tail = ft_last_node(*stack);
		(*stack)->prev = tail;
		(*stack)->next = NULL;
		tmp->prev = NULL;
		tail->next = *stack;
		tail = *stack;
		stack = &((*stack)->next);
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

	if (ft_stack_size(head) > 3)
	{
		tmp = (*tail)->prev;
		(*tail)->prev = NULL;
		(*tail)->next = *head;
		tmp->next = NULL;
		(*head)->prev = *tail;
		head = tail;
		tail = &((*tail)->prev);
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
		(*stack_a)->prev = *stack_b;
		(*stack_b)->prev = NULL;
		(*stack_b)->next = *stack_a;
		tmp->prev = NULL;
		stack_a = stack_b;
		stack_b = &((*stack_b)->next);
	}
	else 
		return ;
	//check for edge cases
}

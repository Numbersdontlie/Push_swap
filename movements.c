/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:51:39 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/01 07:31:22 by luifer           ###   ########.fr       */
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

	if (*stack == NULL || ft_stack_size(stack) == 1)//check for empty or just one element in list
		return ;
	tmp = (*stack)->next;
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = *stack;
	stack = &tmp;
}

void	sa(t_node **stack_a, bool chequea)
{
	ft_swap(stack_a);
	if (chequea == 0)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack_b, bool chequea)
{
	ft_swap(stack_b);
	if (chequea == 0)
		write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b, bool chequea)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (chequea == 0)
	{
		write(1, "sa\n", 3);
		write(1, "sb\n", 3);
	}
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

void	ra(t_node **stack_a, bool chequea)
{
	ft_rotate(stack_a);
	if (chequea == 0)
		write(1, "ra\n", 3);
}

void	rb(t_node **stack_b, bool chequea)
{
	ft_rotate(stack_b);
	if (chequea == 0)
		write(1, "rb\n", 3);
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

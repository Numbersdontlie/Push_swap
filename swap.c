/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:51:39 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/01 14:45:57 by lperez-h         ###   ########.fr       */
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

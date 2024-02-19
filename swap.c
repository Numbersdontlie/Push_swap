/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:51:39 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/19 16:30:51 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file swap.c
 * @brief implement the allowed movements to sort
 * the stack. The movements are: swap, reverse,
 * rotate and push. 
 * 
 * @author Luis Perez (lperez-h)
**/

# include "push_swap.h"

//SWAP -> sa = stack_a, sb = stack_b, ss = stack_a + stack_b
static void	ft_swap(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp_2;

	if (*stack == NULL || (*stack)->next == NULL)//check for empty or just one element in list
		return ;
	tmp = *stack;
	tmp_2 = (*stack)->next;
	tmp->next = tmp_2->next;
	tmp_2->next = tmp;
	*stack = tmp_2;
}

void	sa(t_node **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}

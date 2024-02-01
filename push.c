/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:20:35 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/01 14:45:37 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

void	pa(t_node **stack_a, t_node **stack_b, bool chequea)
{
	ft_push(stack_a, stack_b);
	if (chequea == 0)
		write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b, bool chequea)
{
	ft_push(stack_a, stack_b);
	if (chequea == 0)
		write(1, "pb\n", 3);
}

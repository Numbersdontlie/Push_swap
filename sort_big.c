/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:49:24 by luifer            #+#    #+#             */
/*   Updated: 2024/02/06 17:47:03 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sort_big.c
 * @brief the algorithm to sort a big set of numbers
 * the functions in this file have the purpose
 * of sort in a eficcient way a big set of numbers
 * 
 * @author Luis Perez (lperez-h)
**/

# include "push_swap.h"

//Function to rotate the stack and put on top the desired number (best friend)
void	ft_rotate_stack_top(t_node **stack, t_node *stack_top, char stack_name)
{
	while (stack != stack_top)
	{
		if (stack_name == 'stack_a')
		{
			if (stack_top->above_avg == true)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'stack_b')
		{
			if (stack_top->above_avg == true)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
void	ft_push_swap(t_node **stack_a, t_node **stack_b)
{
	
}
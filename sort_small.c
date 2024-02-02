/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:44:54 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/02 14:38:27 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_sort_stack_3(t_node **stack)
{
	t_node	*high;

	high = ft_find_high(&stack);
	if (*stack == high)
		ra(stack, true);
	else if ((*stack)->next == high)
		rra(stack, true);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, true);
}

void	ft_sort_stack_5(t_node **stack)
{
	
}

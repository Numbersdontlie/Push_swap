/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:44:54 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/05 00:28:29 by luifer           ###   ########.fr       */
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

void	ft_sort_stack_4(t_node **stack_a, t_node **stack_b)
{
	t_node	*low;

	low = ft_find_low(*stack_a);
	if ((*stack_a)->next == low)
		sa(stack_a);
	while (*stack_a != low)
		rra(stack_a);
	pb(stack_a, stack_b);
	ft_sort_stack_3(stack_a);
	pa(stack_b, stack_a);
}

void	ft_sort_stack_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*low;

	low = ft_find_low(stack_a);
	if ((*stack_a)->next == low)
		sa(stack_a);
	while (*stack_a != low)
		rra(stack_a);
	pb(stack_a, stack_b);
	ft_sort_stack_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}
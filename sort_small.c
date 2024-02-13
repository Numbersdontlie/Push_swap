/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:44:54 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/13 15:40:39 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_sort_stack_3(t_node **stack)
{
	t_node	*high;
	int		val;

	printf("entering print3:\n");
	high = ft_find_high(*stack);
	val = high->value;
	if ((*stack)->value == val)
		ra(stack);
	else if ((*stack)->next->value == val) {
		printf("sort 3\n");
		rra(stack);
	}
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	ft_sort_stack_4(t_node **stack_a, t_node **stack_b)
{
	t_node	*low;

	printf("entering print4:\n");
	low = ft_find_low(*stack_a);
	if ((*stack_a)->next == low)
		sa(stack_a);
	while (*stack_a != low) {
		printf("sort 4: value: %i, lowest: %i\n", (*stack_a)->value, low->value);
		rra(stack_a);
		//stack_a = &(*stack_a)->next;
	}
	pb(stack_a, stack_b);
	ft_sort_stack_3(stack_a);
	pa(stack_a, stack_b);
}

void	ft_sort_stack_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*low;

	printf("entering print5:\n");
	low = ft_find_low(*stack_a);
	if ((*stack_a)->next == low)
		sa(stack_a);
	while (*stack_a != low) {
		//printf("sort 5");
		rra(stack_a);
	}
	pb(stack_a, stack_b);
	ft_sort_stack_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

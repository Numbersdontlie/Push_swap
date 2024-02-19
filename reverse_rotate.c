/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:19:49 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/19 19:25:44 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//REVERSE ROTATE -> rra, rrb, rrr
static void	ft_reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;//update the node before last node
		last = last->next;//then move the the last node
	}
	last->next = *stack;
	*stack = last;
	second_last->next = NULL;
}

void	rra(t_node **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	ft_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_best_top(t_node **stack_a, t_node **stack_b, t_node *best)
{
	//printf("reverse rotate best top");
	while ((*stack_a) != best->target_node && (*stack_b) != best)
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}

/*
void	rrr(t_node **stack_a, t_node **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
*/
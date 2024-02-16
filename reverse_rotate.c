/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:19:49 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/05 00:29:50 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//REVERSE ROTATE -> rra, rrb, rrr
void	ft_reverse_rotate(t_node **stack)
{
	t_node	*current;//find previous to last
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;//init at head
	while (current->next != NULL)//iterate until the end
	{
		last = current;//get node before last node
		current = current->next;//iterate until last node
	}
	current->next = *stack;//put the last on top
	*stack = current;//update the head
	last->next = NULL;//update the last node (point to null)
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

void	rrr(t_node **stack_a, t_node **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
}

void	ft_reverse_rotate_best_top(t_node **stack_a, t_node **stack_b, t_node *best)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	while ((*stack_a) != best->target_node && (*stack_b) != best)
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:19:07 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/19 19:50:11 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//ROTATE -> ra, rb, rr
static void	ft_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	last = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	//last = ft_last_node(*stack);//find last node
	tmp = *stack;//save the head
	*stack = (*stack)->next;//update the head -> 2nd node
	last = *stack;
	while (last->next != NULL)
		last = last->next;//get last node
	last->next = tmp;
	tmp->next = NULL;
}

void	ra(t_node **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rotate_best_top(t_node **stack_a, t_node **stack_b, t_node *best)
{
	while ((*stack_a) != best->target_node && (*stack_b) != best)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		write(1, "rr\n", 3);
	}
}

/*
void	rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
*/
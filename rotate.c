/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:19:07 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/09 18:35:26 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//ROTATE -> ra, rb, rr
void	ft_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	last = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = ft_last_node(*stack);//find last node
	tmp = (*stack)->next;//save the head for later
	last->next = *stack;//point the last to the head
	(*stack)->next = NULL;//point next of head to pointer (last one)
	*stack = tmp;//assign the new head
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

void	rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
		write(1, "rr\n", 3);
}

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
	t_node	*tmp;//find last
	t_node	*last;//find previous to last

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;//init at head
	while (tmp->next != NULL)//iterate until the end
	{
		last = tmp;//get node before last node
		tmp = tmp->next;//move to last node
	}
	tmp->next = *stack;//put the last on top
	*stack = tmp;//update the head
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

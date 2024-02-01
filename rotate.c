/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:19:07 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/01 11:19:40 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//ROTATE -> ra, rb, rr
void	ft_rotate(t_node **stack)
{
	t_node *tmp;
	t_node	*tail;

	tail = NULL;
	if (ft_stack_size(stack) > 3)
	{
		tmp = (*stack)->next;
		*tail = ft_last_node(*stack);
		(*stack)->prev = tail;
		(*stack)->next = NULL;
		tmp->prev = NULL;
		tail->next = *stack;
		tail = *stack;
		stack = &((*stack)->next);
	}
	else
		return ;
	//free(tmp)?;
}

void	ra(t_node **stack_a, bool chequea)
{
	ft_rotate(stack_a);
	if (chequea == 0)
		write(1, "ra\n", 3);
}

void	rb(t_node **stack_b, bool chequea)
{
	ft_rotate(stack_b);
	if (chequea == 0)
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b, bool chequea)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (chequea == 0)
		write(1, "rr\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:19:49 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/01 11:20:22 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//REVERSE ROTATE -> rra, rrb, rrr
void	ft_reverse_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tail;

	if (ft_stack_size(stack) > 3)
	{
		*tail = ft_last_node(stack);
		tmp = tail->prev;
		tail->prev = NULL;
		tail->next = *stack;
		tmp->next = NULL;
		(*stack)->prev = tail;
		stack = tail;
		tail = tail->prev;
	}
	else
		return ;
	//free(tmp)?;
}
void	rra(t_node **stack_a, bool chequea)
{
	ft_reverse_rotate(stack_a);
	if (chequea == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b, bool chequea)
{
	ft_reverse_rotate(stack_b);
	if (chequea == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b, bool chequea)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (chequea == 0)
		write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:20:35 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/07 12:20:20 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//PUSH -> pa, pb
void	ft_push(t_node **inicio, t_node **destino)
{
	t_node	*tmp;

	if (*inicio == NULL)
		return ;
	tmp = (*inicio)->next;
	(*inicio)->next = *destino;
	*destino = *inicio;
	*inicio = tmp;
}
//the 1st element at top of b will be the new top element in a
void	pa(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_b, stack_a);
		write(1, "pa\n", 3);
}

//the 1st element at top of a will be the new top element in b
void	pb(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
		write(1, "pb\n", 3);
}

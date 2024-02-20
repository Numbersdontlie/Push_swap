/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:33:00 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/20 21:21:48 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function to sort stack with 2 elements
void	ft_sort_stack_2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

//function to sort stack with 3 elements
void	ft_sort_stack_3(t_node **stack)
{
	t_node	*high;

	//printf("entering sort_3:\n");
	high = ft_find_high(*stack);
	if ((*stack)->value == high->value)
	{
		//printf("entering 1st ra in sort_3:\n");
		ra(stack);
	}
	else if ((*stack)->next->value == high->value) 
	{
		//printf("entering 1st rra in sort_3:\n");
		//printf("buscando el error_sort_3");
		rra(stack);
	}
	if ((*stack)->value > (*stack)->next->value)
	{	
		//printf("entering 1st sa in sort_3:\n");
		sa(stack);
	}
}

//function to sort stack with 4 elements
void	ft_sort_stack_4(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	//printf("entering sort_4:\n");
	tmp = ft_find_low(*stack_a);
	if ((*stack_a)->next == tmp)
		sa(stack_a);
	while (*stack_a != tmp)
	{
		//printf("buscando el error_sort_4");
		rra(stack_a);
	}
	pb(stack_a, stack_b);
	ft_sort_stack_3(stack_a);
	pa(stack_a, stack_b);
}

//function to sort stack with 5 elements
void	ft_sort_stack_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	
	//printf("entering sort_5:\n");
	tmp = ft_find_low(*stack_a);
	//printf("lowest in sort_5:%d\n", tmp->value);
	if ((*stack_a)->next == tmp)
	{
		sa(stack_a);
		//pb(stack_a, stack_b);
	}
	//if (ft_stack_size == 4)
	//	ft_sort_stack_4
	//else 
	//Do the while loop below
	//sort_4
	//printf("printing lowest value %d\n", tmp->value);
	while (*stack_a != tmp)
	{
		//printf("entering in rra sort_5\n");
		//printf("STACK A\n");
		//ft_print_stack(stack_a);
		//printf("STACK B\n");
		//ft_print_stack(stack_b);
		//usleep(50000);
		//printf("aqui esta el error");
		rra(stack_a);
		//printf("aqui esta el error");
	}
	pb(stack_a, stack_b);
	ft_sort_stack_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

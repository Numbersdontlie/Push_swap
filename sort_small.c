/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:44:54 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/14 17:43:11 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//function to sort stack with 3 elements
void	ft_sort_stack_2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_swap(stack_a);
}

void	ft_sort_stack_3(t_node **stack)
{
	t_node	*high;

	printf("entering print3:\n");
	high = ft_find_high(*stack);
	if ((*stack)->value == high->value)
	{
		printf("entering 1st ra in sort_3:\n");
		ra(stack);
	}
	else if ((*stack)->next->value == high->value) 
	{
		printf("entering 1st rra in sort_3:\n");
		rra(stack);
	}
	if ((*stack)->value > (*stack)->next->value)
	{	
		printf("entering 1st sa in sort_3:\n");
		sa(stack);
	}
}

void	ft_sort_more(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = NULL;
	while (ft_stack_size(*stack_a) > 3)//repeat untill there is 3 elements in stack_a
		ft_push_below_avg(stack_a, stack_b);//numbers above avg will go to the bottom of stack, numbers below avg will be pushed to b
	ft_sort_stack_3(stack_a);//sort 3 elements in stack_a
	while (*stack_b)//iterate the whole stack_b
	{
		ft_get_index(*stack_a);//set idx for stack in each iteration
		ft_get_index(*stack_b);//set idx for stack in each iteration
		ft_find_bffo(*stack_a, *stack_b);//find best friend in the current iteration
		ft_calculate_price(*stack_a, *stack_b);//calculate price in the current iteration
		ft_push_from_b_to_a(stack_a, stack_b);//push from stack_b to stack_a
	}
	ft_get_index(*stack_a);//set new idx after all elements come back to stack_a
	tmp = ft_find_low(*stack_a);//find the min number
	if (tmp->arriba_abajo == true)//if min number is in top half
	{
		while (*stack_a != tmp)
			ra(stack_a);//rotate until min is in top of stack
	}
	else//min is in bottom half
		while (*stack_a != tmp)
			rra(stack_a);//reverse rotate until min is in top of stack
}

/*

//function to sort stack with 4 elements
void	ft_sort_stack_4(t_node **stack_a, t_node **stack_b)
{
	t_node	*low;

	printf("entering print4:\n");
	low = ft_find_low(*stack_a);
	if ((*stack_a)->next->value == low->value)
		sa(stack_a);
	while (*stack_a != low) 
	{
		printf("sort 4: value: %i, lowest: %i\n", (*stack_a)->value, low->value);
		rra(stack_a);
		stack_a = &(*stack_a)->next;
	}
	printf("entering pb from sort_4\n");
	pb(stack_a, stack_b);
	ft_sort_stack_3(stack_a);
	printf("entering pa from sort_4\n");
	pa(stack_a, stack_b);
}
void	ft_sort_stack_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*low;

	printf("entering print5:\n");
	low = ft_find_low(*stack_a);
	if ((*stack_a)->next == low)
		sa(stack_a);
	while ((*stack_a)->value != low->value) {
		//printf("sort 5");
		rra(stack_a);
	}
	printf("entering pb from sort_5\n");
	pb(stack_a, stack_b);
	ft_sort_stack_4(stack_a, stack_b);
	printf("entering pa from sort_5\n");
	pa(stack_a, stack_b);
}
*/
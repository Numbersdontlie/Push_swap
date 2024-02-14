/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:49:24 by luifer            #+#    #+#             */
/*   Updated: 2024/02/13 16:30:32 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sort_big.c
 * @brief the algorithm to sort a big set of numbers
 * the functions in this file have the purpose
 * of sort in a eficcient way a big set of numbers
 * 
 * @author Luis Perez (lperez-h)
**/

# include "push_swap.h"

//Function to rotate the stack and put on top the desired number (best friend)
void	ft_rotate_stack_top(t_node **stack, t_node *stack_top, char *stack_name)
{
	while (*stack != stack_top)//iterate until the desired number is in the top of stack
	{
		if (ft_strncmp(stack_name, "stack_a", 7) == 0)//if the stack is A
		{
			if (stack_top->above_avg == true)//check for above/below avg and move it accordingly
				ra(stack);
			else
				rra(stack);
		}
		else if (ft_strncmp(stack_name, "stack_b", 7) == 0)//check for above/below avg and move it accordingly
		{
			if (stack_top->above_avg == true)
				rb(stack);
			else
				rrb(stack);
		}
		stack = &(*stack)->next;
	}
}

//Function to push from stack_b to stack_a
void	ft_push_from_b_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;

	printf("entering into ft_push_from_b_to_a\n");
	if (stack_b == NULL)
		return ;
	node = ft_cheapest_node(*stack_b);//find the cheapest node to push
	printf("cheapest node from push_b_to_a: %d, with value: %d\n", node->price, node->value);
	while (*stack_a != (*stack_b)->target_node && *stack_b != node)//iterate until the top of A is the best friend of B and until the top of B is the best friend of the one in A
	{
		if (node->above_avg == true && node->target_node->above_avg == true)//if both are above average rotate to make it go up and reach the top
			rr(stack_a, stack_b);
		else if (node->above_avg == false && node->target_node->above_avg == false)//if both are below average reverse rotate to make it go down until reach the top
			rrr(stack_a, stack_b);
		stack_a = &(*stack_a)->next;//iterate
		stack_b = &(*stack_b)->next;//iterate
	}
	printf("calling ft_above_avg\n");
	ft_above_avg(*stack_a);//update the above avg flag
	ft_above_avg(*stack_b);//update the above avg flag
	printf("calling ft_rotate_stack_top\n");
	ft_rotate_stack_top(stack_a, node->target_node, "stack_a");//rotate to top of the stack
	ft_rotate_stack_top(stack_b, node, "stack_b");//rotate to top of the stack
	printf("enter into pa from push_from_b_to_a\n");
	pa(stack_b, stack_a);//push the number of top of B to the top of A, where should be the best friend to pair
}

//Function to sort a big stack
void	ft_sort_stack_big(t_node **stack_a, t_node **stack_b)
{
	t_node	*minimo;
	int		val;

	while (ft_stack_size(*stack_a) > 5)
	{
		printf("enter the while 1 in sort big\n");
		ft_push_below_avg(stack_a, stack_b);//push from A to B depending if the number is below or above AVG
	}
	printf("Calling print5:\n");
	ft_sort_stack_5(stack_a, stack_b);//sort 5 numbers remaining in A
	while (stack_b)//iterate in stack_b until is empty
	{
		printf("enter the while 2 in sort big\n");
		ft_recalculate_numbers(*stack_a, *stack_b);//update the numbers:price, best friend, below/above avg 
		printf("calling the function pushing from b to a\n");
		ft_push_from_b_to_a(stack_a, stack_b);//push from B to A. In each iteration the number on top of B should be paired with the best friend in A
	}
	printf("calculating above_avg\n");
	ft_above_avg(*stack_a);//recalculate above/below AVG when all the numbers are in stack A
	minimo = ft_find_low(*stack_a);//find the minimun value in the set
	val = minimo->value;
	if (minimo->above_avg == true)//check if the minimun is above the avg and move it accordingly
	{
		while ((*stack_a)->value != val)
		{	
			printf("enter the while 3 in sort big\n");
			ra(stack_a);
		}
	}
	else//check if the minimun is below the avg and move it accordingly
	{
		while ((*stack_a)->value != val)
		{
			printf("enter the while 4 in sort big\n");
			rra(stack_a);
		}
	}
}


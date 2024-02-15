/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:49:24 by luifer            #+#    #+#             */
/*   Updated: 2024/02/14 17:15:26 by lperez-h         ###   ########.fr       */
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

//Function to push from stack_b to stack_a
void	ft_push_from_b_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;

	printf("entering into ft_push_from_b_to_a\n");
	if (stack_a == NULL || stack_b == NULL)
		return ;
	ft_arriba_abajo(*stack_a);
	ft_arriba_abajo(*stack_b);
	node = ft_cheapest_node(*stack_b);//find the cheapest node in stack_b to push
	if (node == NULL)
		return ;
	printf("cheapest node from push_b_to_a: %d, with value: %d\n", node->price, node->value);
	if (node->arriba_abajo == true && node->target_node->arriba_abajo == true)//if both values are above middle point rotate to make it go up and reach the top
	{
		while (*stack_a != (*stack_b)->target_node && *stack_b != node)//iterate until the top of A is the best friend of B and until the top of B is the best friend of the one in A
			rr(stack_a, stack_b);
	}
	else if (node->arriba_abajo == false && node->target_node->arriba_abajo == false)//if both values are above middle point rotate to make it go up and reach the top
	{
		while (*stack_a != (*stack_b)->target_node && *stack_b != node)//iterate until the top of A is the best friend of B and until the top of B is the best friend of the one in A
			rrr(stack_a, stack_b);
	}
	//printf("calling ft_arriba_abajo\n");
	//ft_arriba_abajo(*stack_a);//update the arriba/abajo flag
	//ft_arriba_abajo(*stack_b);//update the arriba/abajo flag
	//printf("calling ft_rotate_stack_top\n");
	//ft_rotate_stack_top(stack_a, node->target_node, "stack_a");//rotate to top of the stack
	//ft_rotate_stack_top(stack_b, node, "stack_b");//rotate to top of the stack
	printf("enter into pa from push_from_b_to_a\n");
	pa(stack_b, stack_a);//push the number of top of B to the top of A, where should be the best friend to pair
}

//Function to sort a big stack
/*
void	ft_sort_stack_big(t_node **stack_a, t_node **stack_b)
{
	t_node	*minimo;

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
		ft_recalculate_numbers(*stack_a, *stack_b);//update the numbers:price, best friend, arriba/abajo 
		printf("calling the function pushing from b to a\n");
		ft_push_from_b_to_a(**stack_a, **stack_b);//push from B to A. In each iteration the number on top of B should be paired with the best friend in A
	}
	printf("calculating ft_arriba_abajo after send all numbers from B to A\n");
	ft_arriba_abajo(*stack_a);//recalculate arriba/abajo when all the numbers are in stack A
	minimo = ft_find_low(*stack_a);//find the node with the minimun value in the set
	if (minimo->arriba_abajo == true)//check if the minimun is above the avg and move it accordingly
	{
		while ((*stack_a)->value != minimo->value)
		{	
			printf("enter the while 3 in sort big\n");
			ra(stack_a);
		}
	}
	else//check if the minimun is below the avg and move it accordingly
	{
		while ((*stack_a)->value != minimo->value)
		{
			printf("enter the while 4 in sort big\n");
			rra(stack_a);
		}
	}
}
//Function to rotate the stack and put on top the desired number (best friend)
//when run it will move up or down until the desired node is on top of the desired stack
//it should not receive empty parameters
void	ft_rotate_stack_top(t_node **stack, t_node *stack_top, char *stack_name)
{
	if (stack == NULL || stack_top == NULL)
		return ;
	while (*stack != stack_top)//iterate until the desired number is in the top of stack
	{
		if (ft_strncmp(stack_name, "stack_a", 7) == 0)//if the stack is A
		{
			if (stack_top->arriba_abajo == true)//check for arriba/abajo and move it accordingly
				ra(stack);
			else
				rra(stack);
		}
		else if (ft_strncmp(stack_name, "stack_b", 7) == 0)//check for arriba/abajo and move it accordingly
		{
			if (stack_top->arriba_abajo == true)
				rb(stack);
			else
				rrb(stack);
		}
		stack = &(*stack)->next;
	}
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:26:30 by luifer            #+#    #+#             */
/*   Updated: 2024/02/18 21:17:05 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//Function to get the number of movements needed to put a specific number in the top of the stack
void	ft_cost_top(t_node *stack)
{
	int	size;
	int	mid;
	int	i;
	int	count;

	size = 0;
	mid = 0;
	i = 0;
	count = 0;
	if (stack == NULL)//check for empty list
		return ;
	size = ft_stack_size(stack);
	mid = size / 2;
	while (stack)
	{
		if (count < mid)//check if number is above the middle point (true -> arriba)
			i++;//the idx will be the # of movements required to put it on top (goes up with rotate)
		else if (count == mid && (size % 2) == 0)//check if the number is below the middle point (false -> abajo)
			count++;
		else
			i--;
		count++;
		stack->exit_cost = i;//the # of movements will be the diff between size of list and current index (goes down reverse rotate)
		stack = stack->next;
	}
}

//Function to find the best friend of number in stack_b with his pair in stack_a (smallest bigger)
void	ft_find_bffo(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp;
	t_node	*bffo;
	int		best;

	while (stack_b)//iterate stack_b
	{
		best = INT_MAX;//secure init of variable
		tmp = stack_a;//save stack_a for later 
		while (tmp)//iterate the stack_a
		{
			if (tmp->value > stack_b->value && tmp->value < best)//if stack_a value is > than stack_b value && stack_a value is < than best
			{
				best = tmp->value;//save best value
				bffo = tmp;//save the node
			}
			tmp = tmp->next;//step of iteration
		}
		stack_b->target_node = bffo;
		stack_b = stack_b->next;
	}
}

//Function to calculate the price of the movements in stack A and B
void	ft_calculate_price(t_node *stack_a, t_node *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	ft_cost_top(stack_a);//set the cost to top in A
	ft_cost_top(stack_b);//set the cost to top in B
	while (stack_b)
	{
		stack_b->price = stack_b->exit_cost + stack_b->target_node->exit_cost;//in each iteration add the cost to top in B to the cost to top in A A.K.A "target node"
		stack_b = stack_b->next;//iterate in the list
	}
}

//Function to find the node with the less number of movements (cheapest)
t_node	*ft_cheapest_node(t_node *stack)
{
	t_node	*best;
	int		min;

	best = NULL;//init null
	min = INT_MAX;//init with the max int value
	if (stack == NULL)//check for empty list
		return (NULL);
	while (stack)
	{
		if (stack->price < min)//check if price is lower than min
		{
			min = stack->price;//save the new min
			best = stack;//save the node
		}
		stack = stack->next;//iterate
	}
	return (best);//return the node with the min value
}

//this function will push the values that are below the avg to the stack b, the ones above the avg will be moved to the tail of the list
void	ft_push_below_avg(t_node **stack_a, t_node **stack_b)
{
	int	avg;

	//avg = 0;
	//if ((stack_a == NULL && stack_b == NULL) || !(*stack_a))
		//return ;
	avg = ft_average(*stack_a);
	printf("ELEMENT: %d, AVERAGE: %d\n", (*stack_a)->value, avg);
	if ((*stack_a)->value < avg)
		pb(stack_a, stack_b);
	else //if ((*stack_a)->value > avg)
		ra(stack_a);
	//else
		
}

//Function to rotate the stack and put on top the desired number (best friend)
//when run it will move up or down until the desired node is on top of the desired stack
//it should not receive empty parameters
void	ft_rotate_stack_top(t_node **stack, t_node *stack_top, char *stack_name)
{
	if (stack == NULL || stack_top == NULL)
		return ;
	while ((*stack != stack_top) && *stack)//iterate until the desired number is in the top of stack
	{
		if (ft_strncmp(stack_name, "stack_a", 7) == 0)//if the stack is A
		{
			if (stack_top->senal == UP)//check for arriba/abajo and move it accordingly
				ra(stack);
			else
				rra(stack);
		}
		else if (ft_strncmp(stack_name, "stack_b", 7) == 0)//check for arriba/abajo and move it accordingly
		{
			if (stack_top->senal == UP)
				rb(stack);
			else
				rrb(stack);
		}
		stack = &(*stack)->next;
	}
}

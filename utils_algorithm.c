/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:26:30 by luifer            #+#    #+#             */
/*   Updated: 2024/02/09 23:38:31 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//Function to get the number of movements needed to put a specific number in the top of the stack
void	ft_cost_top(t_node *stack)
{
	int	mid;
	
	mid = (ft_stack_size(stack)/2);//calculate the middle point of the list
	while (stack)
	{
		if (stack->index <= mid)//check if number is above the middle point 
			stack->exit_cost = stack->index;//the idx will be the # of movements required to put it on top (goes up with rotate)
		else if (stack->index > mid)//check if the number is below the middle point
			stack->exit_cost = ft_stack_size(stack) - stack->index;//the # of movements will be the diff between size of list and current index (goes down reverse rotate)
		stack = stack->next;
	}
}

//Function to find the best friend of number in stack_a
t_node	ft_find_bffo(t_node	*stack_a, long num)
{
	t_node	*bffo;
	long	count;
	long	tmp;//to save calculation during each iteration
	t_node	*nod_tmp;

	count = INT_MAX;//initialize at max value
	nod_tmp = NULL;
	bffo = NULL;
	*nod_tmp = *stack_a;//store the head for later
	while (stack_a->next != NULL)
	{
		tmp = stack_a->value - num;//calculate the diff between number and all values in stack a
		if((tmp < count) && stack_a->value > num)//check if the calculated value is less than count and if is greater than the number
		{
			count = tmp;//save the value in count
			*bffo = *stack_a;//save the node
		}
		stack_a = stack_a->next;//step of iteration
	}
	stack_a = nod_tmp;//como back to the head after iteration
	return (*bffo);//return the node with the best friend
}

//Function to calculate the price of the movements in stack A and B
void	ft_calculate_price(t_node *stack_a, t_node *stack_b)
{
	ft_cost_top(stack_a);//set the cost to top in A
	ft_cost_top(stack_b);//set the cost to top in B
	while (stack_b)
	{
		stack_b->price = stack_b->exit_cost + stack_b->target_node->exit_cost;//in each iteration add the cost to top in B to the cost to top in A A.K.A "target node"
		stack_b = stack_b->next;//iterate in the list
	}
}

//Function to recalculate the numbers each time that a value is pushed from one stack to another
void	ft_recalculate_numbers(t_node *stack_a, t_node *stack_b)
{
	ft_find_bffo(stack_a, stack_b->value);
	ft_above_avg(stack_a);
	ft_above_avg(stack_a);
	ft_calculate_price(stack_a, stack_b);
}

//Function to find the node with the less number of movements (cheapest)
t_node	*ft_cheapest_node(t_node *stack_b)
{
	t_node	*best;
	int		min;

	best = NULL;//init null
	min = INT_MAX;//init with the max int value
	if (stack_b == NULL)//check for empty list
		return (NULL);
	while (stack_b)
	{
		if (stack_b->price < min)//check if price is lower than min
		{
			min = stack_b->price;//save the new min
			best = stack_b;//save the node
		}
		stack_b = stack_b->next;//iterate
	}
	return (best);//return the node with the min value
}

//this function will push the values that are below the avg to the stack b, the ones above the avg will be moved to the tail of the list
void	ft_push_below_avg(t_node **stack_a, t_node **stack_b)
{
	while (ft_stack_size(*stack_a) > 5)
	{
		ft_above_avg(*stack_a);
		if ((*stack_a)->above_avg == false)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

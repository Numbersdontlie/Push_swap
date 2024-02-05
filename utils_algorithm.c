/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:26:30 by luifer            #+#    #+#             */
/*   Updated: 2024/02/05 22:13:46 by luifer           ###   ########.fr       */
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
t_node	ft_find_bffo(t_node	**stack_a, long num)
{
	t_node	*bffo;
	long	count;
	long	tmp;//to save calculation during each iteration
	t_node	*nod_tmp;

	count = INT_MAX;//initialize at max value
	nod_tmp = *stack_a;//store the head for later
	while (*stack_a)
	{
		tmp = (*stack_a)->value - num;//calculate the diff between number and all values in stack a
		if((tmp < count) && (*stack_a)->value > num)//check if the calculated value is less than count and if is greater than the number
		{
			count = tmp;//save the value in count
			bffo = *stack_a;//save the node
		}
		(*stack_a) = (*stack_a)->next;//step of iteration
	}
	*stack_a = nod_tmp;//como back to the head after iteration
	return (*bffo);//return the node with the best friend
}

//Function to calculate the price of the movements in stack A and B
void	ft_calculate_price(t_node *stack_a, t_node *stack_b)
{
	int	size;

	ft_cost_top(stack_a);//set the cost to top in A
	ft_cost_top(stack_b);//set the cost to top in B
	while (stack_b)
	{
		stack_b->price = stack_b->exit_cost + stack_b->target_node->exit_cost;//in each iteration add the cost to top in B to the cost to top in A A.K.A "target node"
		stack_b = stack_b->next;//iterate in the list
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:26:30 by luifer            #+#    #+#             */
/*   Updated: 2024/02/14 17:07:20 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//Function to get the number of movements needed to put a specific number in the top of the stack
void	ft_cost_top(t_node *stack)
{
	int	size;

	size = 0;
	if (stack == NULL)//check for empty list
		return ;
	size = ft_stack_size(stack);
	ft_get_index(stack);//set an index for each number
	ft_arriba_abajo(stack);//set position for number
	while (stack)
	{
		if (stack->arriba_abajo == true)//check if number is above the middle point (true -> arriba)
			stack->exit_cost = stack->index;//the idx will be the # of movements required to put it on top (goes up with rotate)
		else if (stack->arriba_abajo == false)//check if the number is below the middle point (false -> abajo)
			stack->exit_cost = size - stack->index;//the # of movements will be the diff between size of list and current index (goes down reverse rotate)
		stack = stack->next;
	}
}

//Function to find the best friend of number in stack_a
void	ft_find_bffo(t_node *stack_a, t_node *stack_b)
{
	t_node	*bffo;
	int		best;
	t_node	*nod_tmp;

	while (stack_b->next != NULL && stack_b)
	{
		best = INT_MAX;
		nod_tmp = stack_a;
		while (nod_tmp->next != NULL)
		{
			if (nod_tmp->value > stack_b->value && nod_tmp->value < best)
			{
				best = nod_tmp->value;
				bffo = nod_tmp;
			}
			nod_tmp = nod_tmp->next;
		}
		if (best == INT_MAX)
			stack_b->target_node = ft_find_low(stack_a);
		else
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
	if (stack_b != NULL)
	{
		while (stack_b->next != NULL)
		{
			stack_b->price = stack_b->exit_cost + stack_b->target_node->exit_cost;//in each iteration add the cost to top in B to the cost to top in A A.K.A "target node"
			stack_b = stack_b->next;//iterate in the list
		}
	}
	else
		return ;
}

//Function to recalculate the numbers each time that a value is pushed from one stack to another
void	ft_recalculate_numbers(t_node *stack_a, t_node *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	printf("entering into ft_recalculate_numbers\n");
	ft_find_bffo(stack_a, stack_b);
	ft_arriba_abajo(stack_a);
	ft_arriba_abajo(stack_b);
	ft_calculate_price(stack_a, stack_b);
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
	while (stack->next != NULL)
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
	if (stack_a == NULL)
		return ;
	ft_above_avg(*stack_a);
	if ((*stack_a)->above_avg == false)
		pb(stack_a, stack_b);
	else
		ra(stack_a);
}

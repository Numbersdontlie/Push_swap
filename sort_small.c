/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:44:54 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/19 00:28:45 by lperez-h         ###   ########.fr       */
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
void	ft_sort_stack_4(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = ft_find_low(*stack_a);
	if ((*stack_a)->next == tmp)
		sa(stack_a);
	while (*stack_a != tmp)
		rra(stack_a);
	pb(stack_a, stack_b);
}

void	ft_sort_stack_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	
	tmp = ft_find_low(*stack_a);
	if ((*stack_a)->next == tmp)
		sa(stack_a);
	while (*stack_a != tmp)
		rra(stack_a);
	pb(stack_a, stack_b);
	ft_sort_stack_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	ft_push_from_b_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = ft_cheapest_node(*stack_b);
	printf("entering into ft_push_from_b_to_a\n");
	if (stack_a == NULL || stack_b == NULL )//check for wrong parameters
		return ;
	if (cheapest->senal == UP && cheapest->target_node->senal == UP)
		ft_rotate_best_top(stack_a, stack_b, cheapest);
	else if (cheapest->senal == DOWN && cheapest->target_node->senal == DOWN)
		ft_reverse_rotate_best_top(stack_a, stack_b, cheapest);
	ft_set_senal(*stack_a);
	ft_set_senal(*stack_b);
	printf("cheapest node from push_b_to_a: %d, with value: %d, exit cost: %d, and up/down: %d,\n", cheapest->price, cheapest->value, cheapest->exit_cost, cheapest->senal);
	ft_rotate_stack_top(stack_a, cheapest->target_node, "stack_a");//rotate to top of stack_a the target node of the cheapest node in stack_b
	ft_rotate_stack_top(stack_b, cheapest, "stack_b");//rotate to top of stack_b the cheapest node in stack_b
	pa(stack_b, stack_a);//push top of b on top of a
}


void	ft_sort_more(t_node **stack_a, t_node **stack_b)
{
	t_node	*min;
	int		c;
	//int		avg;

	c = 0;
	while ((ft_stack_size(*stack_a)) >= 5)
	{
		printf("pushing below avg\n");
		usleep(50000);
		//avg = ft_average(*stack_a);
		//printf("ELEMENT: %d, AVERAGE: %d\n", (*stack_a)->value, avg);
		//pb(stack_a, stack_b);
		//if ((*stack_a)->value < avg)
		//	pb(stack_a, stack_b);
		//else if ((*stack_a)->value > avg)
		//	ra(stack_a);
		ft_push_below_avg(stack_a, stack_b);
		//printf("stack A:\n");
		printf("Iteration #:%d\n", c);
		ft_print_stack(stack_a);
		//printf("stack B:\n");
		ft_print_stack(stack_b);
		c++;
	}
	//exit(1);
	ft_sort_stack_5(stack_a, stack_a);
	while (*stack_b)
	{
		ft_recalculate_numbers(*stack_a, *stack_b);
		ft_push_from_b_to_a(stack_a, stack_b);
	}
	ft_set_senal(*stack_a);
	min = ft_find_low(*stack_a);
	if (min->senal == UP)
		while ((*stack_a) != min)
			ra(stack_a);
	else
		while ((*stack_a) != min)
			rra(stack_a);
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
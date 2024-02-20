/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:44:54 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/20 19:34:09 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	ft_rotate_stack_top(t_node **stack, t_node *stack_top, char *stack_name);
static void	ft_push_from_b_to_a(t_node **stack_a, t_node **stack_b);

void	ft_set_objetivo(t_node *stack_a, t_node *stack_b)
{
	t_node	*objetivo;
	t_node	*tmp;
	int		mejor;

	while(stack_b)
	{
		mejor = INT_MAX;
		tmp = stack_a;
		while (tmp)
		{
			if (tmp->value > stack_b->value && tmp->value < mejor)
			{
				mejor = tmp->value;
				objetivo = tmp;
			}
			tmp = tmp->next;
		}
		if (mejor == INT_MAX)
			stack_b->target_node = ft_find_low(stack_a);
		else
			stack_b->target_node = objetivo;
		stack_b = stack_b->next;
	}
}

//Function to rotate the stack and put on top the desired number (best friend)
//when run it will move up or down until the desired node is on top of the desired stack
//it should not receive empty parameters
static void	ft_rotate_stack_top(t_node **stack, t_node *stack_top, char *stack_name)
{
	while (*stack != stack_top)//iterate until the desired number is in the top of stack
	{
		if (ft_strncmp(stack_name, "stack_a", 7) == 0)//if the stack is A
		{
			if (stack_top->senal == UP)//check for arriba/abajo and move it accordingly
				ra(stack);
			else
			{
				//printf("buscando el error_rotate_stack_top");
				rra(stack);
			}
		}
		else if (ft_strncmp(stack_name, "stack_b", 7) == 0)//check for arriba/abajo and move it accordingly
		{
			if (stack_top->senal == UP)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	ft_recalculate_numbers(t_node *stack_a, t_node *stack_b)
{
	ft_set_objetivo(stack_a, stack_b);
	ft_set_senal(stack_a);
	ft_set_senal(stack_b);
	ft_calculate_price(stack_a, stack_b);
}

static void	ft_push_from_b_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = ft_cheapest_node(*stack_b);
	//printf("entering into ft_push_from_b_to_a\n");
	//if (stack_a == NULL || stack_b == NULL )//check for wrong parameters
	//	return ;
	if (cheapest->senal == UP && cheapest->target_node->senal == UP)
		ft_rotate_best_top(stack_a, stack_b, cheapest);
	else if (cheapest->senal == DOWN && cheapest->target_node->senal == DOWN)
		ft_reverse_rotate_best_top(stack_a, stack_b, cheapest);
	ft_set_senal(*stack_a);
	ft_set_senal(*stack_b);
	//printf("cheapest node from push_b_to_a: %d, with value: %d, exit cost: %d, and up/down: %d,\n", cheapest->price, cheapest->value, cheapest->exit_cost, cheapest->senal);
	ft_rotate_stack_top(stack_a, cheapest->target_node, "stack_a");//rotate to top of stack_a the target node of the cheapest node in stack_b
	ft_rotate_stack_top(stack_b, cheapest, "stack_b");//rotate to top of stack_b the cheapest node in stack_b
	pa(stack_a, stack_b);//push top of b on top of a
}


void	ft_sort_more(t_node **stack_a, t_node **stack_b)
{
	t_node	*min;
	//int		c;
	//int		avg;

	//c = 0;
	//printf("entering sort_big:\n");
	while (ft_stack_size(*stack_a) > 5)
	{
		//printf("pushing below avg\n");
		//usleep(50000);
		//printf("Iteration #:%d\n", c);
		ft_push_below_avg(stack_a, stack_b);
		//ft_print_stack(stack_a);
		//ft_print_stack(stack_b);
		//c++;
		//avg = ft_average(*stack_a);
		//printf("ELEMENT: %d, AVERAGE: %d\n", (*stack_a)->value, avg);
		//pb(stack_a, stack_b);
		//if ((*stack_a)->value < avg)
		//	pb(stack_a, stack_b);
		//else if ((*stack_a)->value > avg)
		//	ra(stack_a);
		//printf("stack A:\n");
		//printf("stack B:\n");
	}
	ft_sort_stack_5(stack_a, stack_b);
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
		{	
			printf("buscando el error_sort_more");
			rra(stack_a);
		}
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
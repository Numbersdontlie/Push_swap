/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:49:24 by luifer            #+#    #+#             */
/*   Updated: 2024/02/05 00:45:00 by luifer           ###   ########.fr       */
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

//this function will push the values that are below the avg to the stack b, the ones above the avg will be moved to the tail of the list
void	ft_push_below_avg(t_node **stack_a, t_node **stack_b)
{
	int	avg;

	while (ft_stack_size(*stack_a) > 5)
	{
		avg = ft_average(*stack_a);
		ft_above_avg(*stack_a);
		if ((*stack_a)->above_avg == false)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}


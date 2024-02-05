/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:26:30 by luifer            #+#    #+#             */
/*   Updated: 2024/02/05 10:51:27 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//Function to get the number of movements needed to put a specific number in the top of the stack
int	ft_cost_top(int size, int index)
{
	int		mid;
	int		movements;

	mid = size/2;//calculate the middle point of the list
	if (index <= mid)//check if number is above the middle point 
		movements = index;//the idx will be the # of movements required to put it on top (goes up with rotate)
	else if (index > mid)//check if the number is below the middle point
		movements = size - index;//the # of movements will be the diff between size of list and current index (goes down reverse rotate)
	return (movements);//return # of movements
}


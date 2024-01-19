/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:19:09 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/19 02:13:14 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_node **stack_a, int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	while(argv[i])
	{
		if (ft_check_numbers(argc, argv) != 0)//ToDo
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit(1);
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit(1);
		}
		ft_fill_stack(stack_a, num);//ToDo
		i++;
	}
}
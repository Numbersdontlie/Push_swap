/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:45:31 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/22 11:28:26 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		write (STDERR_FILENO, "Error\n", 6);
	else 
	{
		stack_a = ft_stack_a_init(argc, argv);
		if (ft_stack_size(stack_a) <= 3)
			ft_sort_stack_3(&stack_a);//ToDO
		if (ft_stack_size(stack_a) > 3 && ft_stack_size(stack_a) <= 5)
			ft_sort_stack_5(&stack_a);//ToDo
		if (ft_stack_size(stack_a) > 5)
			turk_algorithm(&stack_a, &stack_b);//ToDo -> ***Main part of the project!***
	}
	//ft_stack_dealloc(&stack_a);
	//ft_stack_dealloc(&stack_b);
	return (0);
}

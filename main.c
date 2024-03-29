/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:45:31 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/19 15:53:09 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
# include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (1);
	ft_check_duplicates(argv);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_insert_data(argv);

	if (argc <=3 )
		ft_sort_stack_2(&stack_a);
	if (argc == 4)
		ft_sort_stack_3(&stack_a);
	if (argc == 5)
		ft_sort_stack_4(&stack_a, &stack_b);
	if (argc == 6)
		ft_sort_stack_5(&stack_a, &stack_b);
	if (argc > 6)
		ft_sort_more(&stack_a, &stack_b);
	//ft_print_stack(&stack_a);
	ft_stack_dealloc(&stack_a);
	//ft_stack_dealloc(&stack_b);
	return (0);
}

/*	
	{
		ft_stack_a_init(stack_a, argv);
	}
	return (0);
	//stack_b = NULL;
	if (argc < 3)
		write (STDERR_FILENO, "Error\n", 6);
	else 
	{
		stack_a = ft_stack_a_init(argc, argv);
		if (ft_stack_size(stack_a) <= 3)
			ft_sort_stack_3(&stack_a);//ToDO
		if (ft_stack_size(stack_a) > 3 && ft_stack_size(stack_a) <= 5)
			ft_sort_stack_5(&stack_a);//ToDo
		if (make (stack_a) > 5)
			turk_algorithm(&stack_a, &stack_b);//ToDo -> ***Main part of the project!***
	}
	//ft_stack_dealloc(&stack_a);
	//ft_stack_dealloc(&stack_b);
	if (argc > 0)
	{
		*stack_a = ft_stack_a_init(argv);
		t_node *curr;
		curr = *stack_a;
		while (curr->next != NULL)
		{
			printf("%d\n", curr->value);
			curr = curr->next;
		}
		return (0);
	}*/

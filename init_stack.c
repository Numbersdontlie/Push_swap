/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/08 15:39:56 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_stack.c
 * @brief Create and initialize the stacks
 * the functions in this file have the purpose
 * of initialize empty list, insert data to it
 * and check the parameters quality.
 * 
 * @author Luis Perez (lperez-h)
**/

# include "push_swap.h"
# include <stdio.h>

t_node	*ft_insert_data(char **argv)
{
	t_node	*stack_a;

	stack_a = ft_insert_node(argv);
	if (ft_check_sorted(stack_a) == 1)
	{
		ft_stack_dealloc(&stack_a);
		exit(1);
	}
	return (stack_a);
}

t_node	*ft_insert_node(char **argv)
{
	int		i;
	long	num;
	t_node	*tmp;
	t_node	*stack_a;
 
	i = 1;
	num = 0;
	stack_a = NULL;
	while(argv[i])
	{
		num = ft_atol(argv[i]);
		tmp = ft_create_node(num);
		ft_add_back(&stack_a, tmp);
		i++;
	}
	return (stack_a);
}

/*
void  print_stack(t_node *root)
{
    while (root != NULL)
    {
//      ft_printf("node->current_position: %d\n", root->index);
        printf("node->data: %d\n", root -> value);
//      ft_printf("node->prev: %p\n", (void *)root -> prev);
//      ft_printf("node->next: %p\n\n", (void *)root -> next);
        root = root -> next;
    }
}
*/
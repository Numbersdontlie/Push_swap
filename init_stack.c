/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/04 23:33:07 by luifer           ###   ########.fr       */
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

t_node	ft_insert_data(t_node **stack, t_node *node)
{
	t_node	*tmp;

	if (stack == NULL || node == NULL)//check fail of allocation
		return ;
	if (*stack == NULL)//check if stack is empty
	{
		stack = node; //if empty make node the head
		return ;
	}
	tmp = *stack;//init at head
	while (tmp->next != NULL)//iterate through list
		tmp = tmp->next;
	tmp->next = node;//add node at the end of list
}

void	ft_stack_init(char **argv)
{
	int		i;
	long	num;
	t_node	*stack_a;
	t_node	*tmp;
 
	i = 1;
	if (ft_check_numbers(argv) == 1 || ft_check_duplicates(argv) == 1 || ft_check_sorted(argv) == 1)
		error_handle();
	while(argv[i])
	{
		
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)//check for overflow
			error_handle();
		tmp = ft_create_node(num);
		ft_insert_data(stack_a, tmp);//insert after all the check are ok
		i++;
	}
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
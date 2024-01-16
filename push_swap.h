/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:45:18 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/16 17:18:30 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

//Structure of my list//
typedef struct	s_node{
	int				value;//value of the node
	int				order_idx;//index of the value when stack is sorted
	int				list_idex;//current index of the value while unsorted
	int				exit_cost;//number of moves to exit stack
	int				target_cost;//number of moves to a sorted position in other stack
	int				optimized;//check if double moves in stacks are allowed
	int				priority;//cost of sorting each value on a particular stack, so to choose the cheapest
	struct s_node	*next;//next node
	struct s_node	*prev;//prev node
}	t_node;

//this structure help to reduce the # of parameters when passing 2 stack to a function
typedef struct	s_stacks
{
	struct s_node **stack_a;
	struct s_node **stack_b;
}	t_stacks;

//this structure helps to keep track of some of the handy 
//details we'll need when sorting 
typedef struct	s_node_details
{
	int	pos;
	int	value;
	struct s_node	*node;
}	t_node_details;

//This struct help to monitor nodes with max and min
typedef struct	s_node_details
{
	t_node_details *min;
	t_node_details *mid;
	t_node_details *max;
}	t_details;
//Error handler (ToDo)

//Operations in stack (ToDo)

//Lenght of stack (ToDo)

//Last node (ToDo)

//Min and Max nodes (ToDo)

//String split (ToDo)

//Argv split (ToDo)

//Utils (ToDo)

#endif
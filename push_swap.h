/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:45:18 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/25 23:17:47 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.h
 * @brief Functions prototype for the project
 * 
 * This contains the prototypes for the push-swap project
 * and the data structures needed for the project
 * 
 * @author Luis Perez (lperez-h)
**/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

//Structure of my node//
typedef struct	s_node
{
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

/*typedef struct	t_list
{
	struct	*head;
	struct	*tail;
}	t_list;*/

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
typedef struct	s_node_data
{
	t_node_details *min;
	t_node_details *mid;
	t_node_details *max;
}	t_details;

//Error handler (ToDo)

//**MOVEMENTS**//
/**
 * @brief swap the stack.
 * 
 * the function swap the first 2 values of the stack, the 1st value
 * becomes the 2nd and viceversa. The rest of the stack remains as
 * it was before the movement. 
 * 
 * @param **head: the pointer to the head of the list
 * @return void
**/
void	ft_swap(t_node **head);

/**
 * @brief rotate the stack.
 * 
 * the function rotate the stack: the 1st value of the stack will become
 * the last value. The rest of the stack will move 1 position up
 * 
 * @param **head: the pointer to the head of the list
 * @return void
**/
void	ft_rotate(t_node **head, t_node **tail);

/**
 * @brief reverse the stack.
 * 
 * the function reverse the stack: the last value of the stack will become
 * the 1st value. The rest of the stack will move 1 position down
 * 
 * @param **head: the pointer to the head of the list
 * @param **tail: the pointer to the tail of the list
 * @return void
**/
void	ft_reverse_rotate(t_node **head, t_node **tail);

/**
 * @brief push the stack.
 * 
 * the function push the stack: the 1st value of the stack will become
 * the 1st value of the other. The rest of the stack receiving the new 
 * value will move 1 position down. The stack from where the number was 
 * sent, will update the head pointer.
 * 
 * @param **head: the pointer to the head of the list
 * @param **tail: the pointer to the tail of the list
 * @return void
**/
void	ft_push(t_node **head_a, t_node **head_b);

//**STACK INITIALIZATION**//
/**
 * @brief Initialize the node.
 * 
 * In case the linked list is empty, the function will initialize a node
 * and assign a value to node->value. It will also set the prev and next
 * pointer to NULL and will assign the head and tail to the new created 
 * node.
 * 
 * @param **head: the pointer to the head of the list
 * @param **tail: the pointer to the tail of the list
 * @return void
**/
void	ft_node_init(t_node **head, t_node **tail, int num);

/**
 * @brief Insert data into the list.
 * 
 * This function add data to the tail of the list, the function create nodes 
 * and assign values to it node->value. If the list is empty the function call
 * the ft_node_init function. It also update the prev and next pointer and also
 * the new tail. 
 * 
 * @param **head: the pointer to the head of the list
 * @param **tail: the pointer to the tail of the list
 * @param num the value to add to the node
 * @return void
**/
void	ft_insert_data(t_node **head, t_node **tail, int num);

/**
 * @brief check if the list have only numbers
 * 
 * This function checks that only integers numbers are stored in the list and 
 * also check for the INT_MIN and INT_MAX arguments 
 * 
 * @param **head: the pointer to the head of the list
 * @return 1 for false, 0 for true
**/
int		ft_check_numbers(t_node **head);

/**
 * @brief check if the list is already sorted
 * 
 * This function checks if the parameters are already sorted
 * 
 * @param **head: the pointer to the head of the list
 * @return 1 for false, 0 for true
**/
int		ft_check_sorted(t_node **head);

/**
 * @brief check for duplicates
 * 
 * This function checks if there are duplicated parameters
 * in the list
 * 
 * @param **head: the pointer to the head of the list
 * @return 1 for false, 0 for true
**/
int		ft_check_duplicates(t_node **head);

/**
 * @brief initialize the stack_a
 * 
 * This function initialize the stack_a, for this it will convert
 * the arguments received in the command line into long integers,
 * and make quality checks. It will deallocate if needed. 
 * 
 * @param **argv: the arguments received by the program
 * @return *head: a pointer to the head of the list
**/
t_node	*ft_stack_a_init(char **argv);

/**
 * @brief initialize the stack_b
 * 
 * This function initialize the stack_b empty. It will create a
 * stack of size (stack_a - 3).
 * 
 * @param **stack_a: the stack_a
 * @return *head: a pointer to the head of the list
**/
t_node	ft_stack_b_init(t_node **stack_a);

//Utils of stack
/**
 * @brief deallocate the stack
 * 
 * This function deallocate the stack (memory free)
 * it iterate through the whole list and free the 
 * memory allocated. It also set head and tail to NULL
 * 
 * @param **head: a pointer to the head of the list
 * @param **tail: a pointer to the tail of the list
 * @return void
**/
void	ft_stack_dealloc(t_node **head, t_node **tail);

/**
 * @brief measure the size of the stack
 * 
 * This function count the number of nodes inside
 * the list
 * 
 * @param **head: the pointer to the head of the list
 * @return count: the number of nodes in the list
**/
int		ft_stack_size(t_node **head);

void  print_stack(t_node *root);

//Last node (ToDo)

//Min and Max nodes (ToDo)

//Argv split (ToDo)

//Utils (ToDo)
/**
 * @brief convert the arguments
 * 
 * This function convert the arguments received from user
 * into long integer
 * 
 * @param *nptr: the pointer to the argument received
 * @return result: the number already converted
**/
int	ft_atol(const char *nptr);

/**
 * @brief check the data type
 * 
 * This function check for integers data type
 * 
 * @param c: the number to check
 * @return True or False
**/
int	ft_isdigit(int c);
#endif
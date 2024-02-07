/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:45:18 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/07 16:04:14 by lperez-h         ###   ########.fr       */
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
# include <stdbool.h>

//Structure of my node//
typedef struct	s_node
{
	int				value;//value of the node
	int				exit_cost;//number of moves to exit stack
	int				price;//sum of exit cost + exit cost best friend
	int				index;//index inside the list
	bool			above_avg;//check if value is above the average 
	struct s_node	*next;//next node
	struct s_node	*target_node;//target node in the other stack
}	t_node;

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
 * @brief swap the stack_a
 * 
 * the function swap the first two elements of stack_a
 * 
 * @param **stack_a: the pointer to the head of the list
 * @return void
**/
void	sa(t_node **stack_a);

/**
 * @brief swap the stack_b
 * 
 * the function swap the first two elements of stack_b
 * 
 * @param **stack_b: the pointer to the head of the list
 * @return void
**/
void	sb(t_node **stack_b);

/**
 * @brief swap the stack_a and stack_b
 * 
 * the function swap the first two elements of stack_a and stack_b 
 * at the same time
 * 
 * @param **stack_a: the pointer to the head of the list
 * @param **stack_b: the pointer to the head of the list
 * @return void
**/
void	ss(t_node **stack_a, t_node **stack_b);

/**
 * @brief rotate the stack.
 * 
 * the function rotate the stack, it will send the first  
 * element of the stack to the bottom of the stack, the rest of the stack
 * will move 1 position up
 * 
 * @param **stack the stack to be rotated
 * @return void
**/
void	ft_rotate(t_node **stack);

/**
 * @brief rotate the stack_a.
 * 
 * the function rotate the stack, it will send the first  
 * element of the stack to the bottom of the stack, the rest of the stack
 * will move 1 position up
 * 
 * @param **stack_a: the stack_a
 * @return void
**/
void	ra(t_node **stack_a);

/**
 * @brief rotate the stack_b.
 * 
 * the function rotate the stack, it will send the first  
 * element of the stack to the bottom of the stack, the rest of the stack
 * will move 1 position up
 * 
 * @param **stack_b: the stack_b
 * @return void
**/
void	rb(t_node **stack_b);

/**
 * @brief rotate the stacks_a and stack_b.
 * 
 * the function rotate the stack_a and stack_b at the same time, it will send the first  
 * element of the stacks to the bottom of the stacks, the rest of the stacks
 * will move 1 position up
 * 
 * @param **stack_a: the stack_a
 * @param **stack_b: the stack_b
 * @return void
**/
void	rr(t_node **stack_a, t_node **stack_b);

/**
 * @brief reverse the stack.
 * 
 * the function reverse the stack: the last value of the stack will become
 * the 1st value. The rest of the stack will move 1 position down
 * 
 * @param **stack: the pointer to the head of the list
 * @return void
**/
void	ft_reverse_rotate(t_node **stack);

/**
 * @brief reverse rotate the stack.
 * 
 * the function reverse rotate the stack, it will send the last 
 * element of the stack on top of the stack, the rest of the stack
 * will move 1 position down
 * 
 * @param **stack_a: the stack_a
 * @return void
**/
void	rra(t_node **stack_a);

/**
 * @brief reverse rotate the stack.
 * 
 * the function reverse rotate the stack, it will send the last 
 * element of the stack on top of the stack, the rest of the stack
 * will move 1 position down
 * 
 * @param **stack_b: the stack_b
 * @return void
**/
void	rrb(t_node **stack_b);

/**
 * @brief reverse rotate stack_a and stack_b
 * 
 * the function reverse rotate the stack_a and stack_b simultaneously. It will send the last 
 * element of the stacks on top of the stacks, the rest of the stacks numbers
 * will move 1 position down
 * 
 * @param **stack_a: the stack_a
 * @param **stack_b: the stack_b
 * @return void
**/
void	rrr(t_node **stack_a, t_node **stack_b);

/**
 * @brief push the stack.
 * 
 * the function push the stack: the 1st value of the stack inicio will become
 * the 1st value of the stack destino. The rest of the stack destino
 * will move 1 position down. The stack inicio will update the head pointer.
 * 
 * @param **inicio: the stack sending the number
 * @param **destino: the stack receiving the number
 * @return void
**/
void	ft_push(t_node **inicio, t_node **destino);

/**
 * @brief push the stack.
 * 
 * the function push the top of stack_b on top of stack_a
 * 
 * @param **stack_a: the stack_a
 * @param **stack_b: the stack_b
 * @return void
**/
void	pa(t_node **stack_a, t_node **stack_b);

/**
 * @brief push the stack.
 * 
 * the function push the top of stack_a on top of stack_b
 * 
 * @param **stack_a: the stack_a
 * @param **stack_b: the stack_b
 * @return void
**/
void	pb(t_node **stack_a, t_node **stack_b);

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
 * This function add data to the list, the function takes a node
 * and add it at the end of the list
 * 
 * @param **stack: the pointer to the head of the list
 * @param *node: the node to add an the end of the list
 * @return t_node
**/
t_node	ft_insert_data(t_node **stack, t_node *node);

/**
 * @brief check if the list have only numbers
 * 
 * This function checks that only integers numbers are stored in the list and 
 * also check for the INT_MIN and INT_MAX arguments 
 * 
 * @param **head: the pointer to the head of the list
 * @return 1 for false, 0 for true
**/
int		ft_check_numbers(char **argv);

/**
 * @brief check if the list is already sorted
 * 
 * This function checks if the parameters are already sorted
 * 
 * @param **head: the pointer to the head of the list
 * @return 1 for false, 0 for true
**/
int		ft_check_sorted(char **argv);

/**
 * @brief check for duplicates
 * 
 * This function checks if there are duplicated parameters
 * in the list
 * 
 * @param *stack: the pointer to the head of the list
 * @param num: the value to compare if number already exist
 * @return 1 for false, 0 for true
**/
int		ft_check_duplicates(char **argv);

/**
 * @brief initialize the stack_a
 * 
 * This function initialize the stack_a, for this it will convert
 * the arguments received in the command line into long integers,
 * and make quality checks. It will deallocate if needed. 
 * 
 * @param **argv: the arguments received by the program
 * @return void
**/
void	ft_stack_init(char **argv);

/**
 * @brief check for errors and exit
 * 
 * This function check for errors and exit the program
 * 
 * @param void: no arguments
 * @return void
**/
void	ft_error_handle(void);

/**
 * @brief initialize the stack_b
 * 
 * This function initialize the stack_b empty. It will create a
 * stack of size (stack_a - 3).
 * 
 * @param **stack_a: the stack_a
 * @return *head: a pointer to the head of the list
**/
void	ft_stack_b_init(t_node **stack_a);

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
void	ft_stack_dealloc(t_node **head);

/**
 * @brief measure the size of the stack
 * 
 * This function count the number of nodes inside
 * the list
 * 
 * @param **head: the pointer to the head of the list
 * @return count: the number of nodes in the list
**/
int		ft_stack_size(t_node *stack);

void	ft_print_stack(t_node *stack);

/**
 * @brief find the last node of the list
 * 
 * This function finds and return the last node of the list
 * 
 * @param head: the head of the list
 * @return the last node of the list
**/
t_node	ft_last_node(t_node *stack);

/**
 * @brief find the lowest number in the set
 * 
 * This function finds the number with the lowest value in the set 
 * and return the node containing it
 * 
 * @param *stack: a pointer to the the head of the list
 * @return the node with the lowest number
**/
t_node	*ft_find_low(t_node *stack);

/**
 * @brief find the highest number in the set
 * 
 * This function finds the number with the highest value in the set 
 * and return the node containing it
 * 
 * @param *stack: a pointer to the the head of the list
 * @return the node with the highest number
**/
t_node	*ft_find_high(t_node *stack);

/**
 * @brief create a node for the list
 * 
 * This function takes a number and create a node with it
 * 
 * @param num: a integer number to save inside the node
 * @return the node with the stored number
**/
t_node	ft_create_node(int num);

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
 * @brief sort a small stack
 * 
 * This function sort a stack of size 3
 * 
 * @param c: the stack to sort
 * @return void
**/
void	ft_sort_stack_3(t_node **stack);

/**
 * @brief sort a small stack
 * 
 * This function sort a stack of size 4
 * 
 * @param stack_a: the stack to sort
 * @param stack_b: the auxiliary stack to help to sort
 * @return void
**/
void	ft_sort_stack_4(t_node **stack_a, t_node **stack_b);

/**
 * @brief sort a small stack
 * 
 * This function sort a stack of size 5
 * 
 * @param stack_a: the stack to sort
 * @param stack_b: the auxiliary stack to help to sort
 * @return void
**/
void	ft_sort_stack_5(t_node **stack_a, t_node **stack_b);

/**
 * @brief sort a big stack
 * 
 * This function sort a big stack (size more than 5)
 * 
 * @param stack_a: the stack to sort
 * @param stack_b: the auxiliary stack to help sort
 * @return void
**/
void	ft_sort_stack_big(t_node **stack_a, t_node **stack_b);

/**
 * @brief make the 1st movements to sort big stacks
 * 
 * This function will send the number below the average to the 
 * stack_b, the ones above the avg will be send to the tail
 * of the stack_a
 * 
 * @param stack_a: the stack with initial numbers
 * @param stack_b: the empty stack to use as aux stack
 * @return void
**/
void	ft_push_below_avg(t_node **stack_a, t_node **stack_b);

/**
 * @brief calculate the price of movements
 * 
 * This function will calculate the number of movements needed
 * to put a specific number in the top of the stack_a and stack_b
 * 
 * @param stack_a: stack with numbers
 * @param stack_b: stack with numbers
 * @return void
**/
void	ft_calculate_price(t_node *stack_a, t_node *stack_b);

/**
 * @brief rotate stack to the top
 * 
 * This function will rotate specific numbers to the top of the stack
 * 
 * @param stack: stack with numbers
 * @param stack_top: the node that we want to put in the top
 * @param stack_name: the name of the stack containing the number
 * @return void
**/
void	ft_rotate_stack_top(t_node **stack, t_node *stack_top, char stack_name);

/**
 * @brief push the numbers from one stack to another
 * 
 * This function will push the numbers from stack_b to the stack_a
 * in this function is where the most of the algorithm to sort the big stack
 * occurs
 * 
 * @param stack_a: stack with numbers
 * @param stack_b: stack with numbers 
 * @return void
**/
void	ft_push_from_b_to_a(t_node **stack_a, t_node **stack_b);

/**
 * @brief calculate the cost to top
 * 
 * This function calculate the number of movements needed to bring a specific
 * node to the top of the stack
 * 
 * @param stack: stack with numbers
 * @return void
**/
void	ft_cost_top(t_node *stack);

/**
 * @brief find the best friend of the number to be pushed
 * 
 * This function calculate the number with the less positive difference
 * between the number and nodes inside the list
 * 
 * @param stack_a: stack with numbers already sorted where the number from B will be pushed
 * @return the node containing the best friend A.K.A the one with the less positive difference
**/
t_node	ft_find_bffo(t_node	**stack_a, long num);

/**
 * @brief recalculate numbers after each iteration
 * 
 * This function re calculate numbers after each iteration
 * the updated numbers will be best friend, above avg and price for each node
 * 
 * @param stack_a: stack with numbers
 * @param stack_b: stack with numbers
 * @return void
**/
void	ft_recalculate_numbers(t_node *stack_a, t_node *stack_b);

/**
 * @brief find the cheapest node
 * 
 * This function calculate the cheapest node to be moved on top
 * between the number and nodes inside the list
 * 
 * @param stack_a: stack with numbers already sorted where the number from B will be pushed
 * @return the node containing the best friend A.K.A the one with the less positive difference
**/
t_node	*ft_cheapest_node(t_node *stack_b);

/**
 * @brief get the index for each node
 * 
 * This function calculate the index for each node in the list
 * 
 * @param stack: stack with nodes that will get an index
 * @return void
**/
void	ft_get_index(t_node *stack);

/**
 * @brief check if a number is below or above the average
 * 
 * This function check if a number is below or above the average
 * 
 * @param stack: stack with nodes that will get a flag depending if they are above/below the average
 * @return void
**/
void	ft_above_avg(t_node *stack);

/**
 * @brief calculates the average of the stack
 * 
 * This function calculates dinamycally the average of the stack
 * 
 * @param stack: stack with nodes from which the average will be calculated
 * @return int
**/
int	ft_average(t_node *stack);

/**
 * @brief check which algorithm to launch
 * 
 * This function decides which algorithm to call based on the numbers to be sorted
 * 
 * @param stack_a: stack with numbers 
 * @param stack_b: stack with numbers
 * @return void
**/
void	router(t_node **stack_a, t_node **stack_b);

#endif
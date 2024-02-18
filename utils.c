/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:02:13 by lperez-h          #+#    #+#             */
/*   Updated: 2024/02/18 13:26:50 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file utils.c
 * @brief Helper functions to operate during project
 * the functions help to: convert char to long, check
 * for digits, among others
 * 
 * @author Luis Perez (lperez-h)
**/

#include "push_swap.h"

//Function to convert string to integers to receive arguments
int	ft_atol(char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == 32))
		nptr++;
	if ((*nptr == 43) || (*nptr == 45))
	{
		if (*nptr == 45)
			sign = -1;
		nptr++;
	}
	if (*nptr && (*nptr < 48 || *nptr > 57))//check next after symbol is a number
		ft_error_handle();
	while (((*nptr >= 48) && (*nptr <= 57)))
	{
		result = ((result * 10) + (*nptr - 48));
		nptr++;
	}
	if (*nptr && (*nptr < 48 || *nptr > 57))
		ft_error_handle();
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		ft_error_handle();
	return (result * sign);
}

//Function to compare two strings
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while ((n += '0') && (*p1 != '\0') && (*p1 == *p2))
	{
		p1++;
		p2++;
		n--;
	}
	if (n != '\0')
		return (*p1 - *p2);//not equals
	else
		return (0);//string are equals
}

void	ft_set_senal(t_node *stack)
{
	int	i;
	int	mid;
	
	i = 0;
	if (stack == NULL)
		return ;
	mid = (ft_stack_size(stack) / 2);
	while (stack)
	{
		stack->senal = UP;//True: arriba. false:abajo
		if (i > mid)
			stack->senal = DOWN;//True: arriba. false:abajo
		i++;
		stack = stack->next;
	}
}

void	print_stack(t_node *stack)
{
	if (stack == NULL)
	{
		printf("empty stack\n");
		return ;
	}
	while (stack)
	{
		printf("value: %d, cost: %d\n", stack->value, stack->exit_cost);
		stack = stack->next;
	}
}

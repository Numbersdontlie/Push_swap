/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:31:43 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/16 17:34:24 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//Function to convert string to integers to receive arguments
int	ft_atoi(char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	while (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == 32))
		nptr++;
	if ((*nptr == 43) || (*nptr == 45))
	{
		if (*nptr == 45)
			sign = -1;
		nptr++;
	}
	result = 0;
	while (((*nptr >= 48) && (*nptr <= 57)))
	{
		result = ((result * 10) + (*nptr - 48));
		nptr++;
	}
	return (result * sign);
}

//Function to parse the arguments when received as several arguments in argv
char	**args_parser(int argc, char **argv)
{
	int	i;
	int	*numeros;
	int	num;

	i = 1;
	num = 0;
	numeros = (int *)malloc((argc - 1) * sizeof(int));
	if (numeros == NULL)
		return (1);
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num == 0 && argv[i][0] != '0')
		{
			write (STDERR_FILENO, "Error", 5);
			write(1, "\n", 1);
			free(numeros);
			exit (1);
		}
		//insert into array of numbers 
		numeros[i - 1] = num;
		i++;
	}
	return (numeros);
}

void	ft_parser(char *s)
{
	//Loop
		//check for sign of each argument
		//check if the arguments are digits 
		//convert from string to number and save it
		//check for MAX_INT and MIN_INT
		//Add the value to the stack A
	//Once the stack is populated check for duplicates
	//Return something
}

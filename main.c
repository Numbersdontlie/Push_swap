/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:45:31 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/18 21:32:56 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;
	char	*parser;
	
	i = 0;
	j = 0;
	
	if (argc == 2)
	{
		tmp = ft_split(argv[1][i], ' ');//split the numbers and save in tmp
		size = sizeof(tmp) / sizeof(tmp[0]);//size of the array
		while (j <= size)
		{
			j++;//goes through the whole array until last element
		}
		//start to fill the linked list with this last element
	}
	else if (argc > 2)
	{
		parser = args_parser(argc, **argv);
		size = sizeof(parser) / sizeof(parser[0]);
		while (j <= size)
		{
			j++;//goes through the whole array until last element
		}
		//start to fill the linked list with this last element
	}
}*/

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
	{
		write (STDERR_FILENO, "Error", 5);
		write (1, "\n", 1);
	}
	else 
	{
		if (argc == 2)
		{
		//split the argv arg_parse
		//fill the stack a
		}
		/*else if (argc > 2)
		{
		//split the argv
		//fill the stack a 
		}*/
	}
}

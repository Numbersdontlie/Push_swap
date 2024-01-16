/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:58:37 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/16 13:09:07 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//this function determine the lenght of the next word in the string
static size_t	palabra(char *s, char c)
{
	size_t	l;

	l = 0;
	while((*s) && (*s != c))
	{
		l++;
		s++;
	}
	return (l);
}

//this function counts the number of words in the string
static size_t	csplit(char *s, char c)
{
	size_t	count;
	size_t	cfound;

	count = 0;
	cfound = 1;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if ((*s != c) && (cfound))
		{
			count++;
			cfound = 0;
		}
		if ((*s == c))
			cfound = 1;
		s++;
	}
	return (count);
}

//This function allocates memory for a word and copies the word 
//into the allocated memory
static int	wword(char *s, char **d, char c)
{
	char	*temp;
	
	*d = (char *)malloc((sizeof(char) * (palabra(s, c) + 1)));
	if (*d == NULL)
		return (0);
	temp = *d;
	while ((*s) && (*s != c))
		*temp++ = *s++;
	*temp = '\0';
	return (1);
}

//This function is used to free memory allocated for strings. 
//It iterates through the strings pointed to by 's2' and then 
//frees the memory allocated for the array of strings pointed to
//by 's1'
static void	ft_free(char **s1, char **s2)
{
	while (s2 != s1)
		free(*s2);
	free(s1);
}

//This is the main function that splits the input string into an array 
//of substrings. It uses the previously defined helper functions to count 
//the number of words, allocate memory for each word, and copy the words 
//into the allocated memory. It also handles the case where memory allocation 
//fails and frees the memory in case of an error. The resulting array of 
//strings is terminated with a NULL pointer.
char	**ft_split(char *s, char c)
{
	char	**resultado;
	char	**ptr;
	size_t	count;

	count = csplit(s, c);
	resultado = malloc(sizeof(char *) * (count + 1));
	if ((resultado == NULL) || (s == NULL))
		return (NULL);
	ptr = resultado;
	while (*s == c)
		s++;
	while (count--)
	{
		if (wword(s, ptr, c) == 0)
		{
			ft_free(resultado, ptr);
			return (NULL);
		}
		s = s + palabra(s, c);
		while (*s == c)
			s++;
		ptr++;
	}
	*ptr = NULL;
	return (resultado);
}

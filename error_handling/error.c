/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:06:19 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/12 19:52:33 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print_errf.h"
#include "rules.h"
#include "error_handling.h"

void	free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (args[i])
			free(args[i]);
		i++;
	}
	if (args)
		free(args);
}

/*	Panic_exit : 
 *	
 *		This function is called when something wrong
 *			happen's during the program runtime.
 *			It will clear all the stack used, clear  
 *			op if it's dynamically allocated and
 *			exit with failure signals
 */

void	panic_exit(t_list **a, t_list **b, char *op, int flag)
{
	if (!flag)
		print_errf("Error\n");
	clear_stack(*a);
	if (b != NULL)
		clear_stack(*b);
	if (op != NULL)
		free(op);
	if (b != NULL)
		free(b);
	exit(EXIT_FAILURE);
}

/*
	Print error : 

      This function print a string into stderror
*/

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

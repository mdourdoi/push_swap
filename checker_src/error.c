/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:04:07 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 11:04:09 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "print_errf.h"
#include "rules.h"

/*	Panic_exit : 
 *	
 *		This function is called when something wrong
 *			happen's during the program runtime.
 *			It will clear all the stack used, clear  
 *			op if it's dynamically allocated and
 *			exit with failure signals
 * */

void	panic_exit(t_list **a, t_list **b, char *op)
{
	print_errf("error\n");
	clear_stack(*a);
	clear_stack(*b);
	if (op != NULL)
		free(op);
	exit(EXIT_FAILURE);
}

void	check_error(t_list **a, t_list **b, char *op)
{
	if (ft_strcmp(op, "error\n") == 0)
		panic_exit(a, b, op);
}

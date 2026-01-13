/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:04:07 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/13 17:13:56 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_bool	is_op(char *op)
{
	if (ft_strcmp(op, "pa\n") == 0)
		return (TRUE);
	if (ft_strcmp(op, "pb\n") == 0)
		return (TRUE);
	if (ft_strcmp(op, "sa\n") == 0)
		return (TRUE);
	if (ft_strcmp(op, "sb\n") == 0)
		return (TRUE);
	if (ft_strcmp(op, "ss\n") == 0)
		return (TRUE);
	if (ft_strcmp(op, "ra\n") == 0)
		return (TRUE);
	if (ft_strcmp(op, "rb\n") == 0)
		return (TRUE);
	if (ft_strcmp(op, "rr\n") == 0)
		return (TRUE);
	if (ft_strcmp(op, "rra\n") == 0)
		return (TRUE);
	if (ft_strcmp(op, "rrb\n") == 0)
		return (TRUE);
	if (ft_strcmp(op, "rrr\n") == 0)
		return (TRUE);
	return (FALSE);
}

/*
 * 	Check_op : 
 *
 * 		this function will check if the op string receive from
 * 			push_swap is a valid op
 * */
void	check_op(char *op, t_list **a, t_list **b)
{
	if (is_op(op) == FALSE)
	{
		drain_pipe();
		panic_exit(a, b, op, PRINT_ERROR);
	}
}

/*
 * 	drain_pipe : 
 *
 * 		drain all stdin in case of error
 * */
void	drain_pipe(void)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		free(op);
		op = get_next_line(0);
	}
	if (op)
		free(op);
}

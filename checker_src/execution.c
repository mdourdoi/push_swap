/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:04:11 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 11:04:12 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

/*	Exxecute : 
 *
 *		This function will read the actual operation
 *			sent in stdin and will execution the corresponding
 *		operation
 */

void	execute(char *op, t_list **a, t_list **b, t_rule *rules)
{
	if (ft_strcmp(op, "pa\n") == 0)
		ft_push(a, '\0', b, rules);
	if (ft_strcmp(op, "pb\n") == 0)
		ft_push(b, '\0', a, rules);
	if (ft_strcmp(op, "sa\n") == 0)
		ft_swap(a, '\0', 0, rules);
	if (ft_strcmp(op, "sb\n") == 0)
		ft_swap(b, '\0', 0, rules);
	if (ft_strcmp(op, "ra\n") == 0)
		ft_rotate(a, '\0', 0, rules);
	if (ft_strcmp(op, "rb\n") == 0)
		ft_rotate(b, '\0', 0, rules);
	if (ft_strcmp(op, "rr\n") == 0)
		ft_rotate_both(*a, *b, rules);
	if (ft_strcmp(op, "rra\n") == 0)
		ft_reverse_rotate(a, '\0', 0, rules);
	if (ft_strcmp(op, "rrb\n") == 0)
		ft_reverse_rotate(b, '\0', 0, rules);
	if (ft_strcmp(op, "rrr\n") == 0)
		ft_reverse_rotate_both(*a, *b, rules);
}

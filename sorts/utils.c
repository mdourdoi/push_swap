/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:44:51 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/29 17:08:37 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt_round(int n)
{
	int	x;

	x = 0;
	while ((x + 1) * (x + 1) <= n)
		x++;
	return (x + 1);
}

void	ft_select_rot_a(t_list **stack, int rot, int rev_rot, t_rule *rules)
{
	if (rot > rev_rot)
	{
		while (rev_rot-- > 0)
			ft_reverse_rotate(stack, 'a', 1, rules);
	}
	else
	{
		while (rot-- > 0)
			ft_rotate(stack, 'a', 1, rules);
	}
}

void	ft_select_rot_b(t_list **stack, int rot, int rev_rot, t_rule *rules)
{
	if (rot > rev_rot)
	{
		while (rev_rot-- > 0)
			ft_reverse_rotate(stack, 'b', 1, rules);
	}
	else
	{
		while (rot-- > 0)
			ft_rotate(stack, 'b', 1, rules);
	}
}

float	ft_get_disorder(t_list *stack)
{
	long		errors;
	long		pairs;
	t_list		*rest;

	if (!stack || !stack->next)
		return (0.0);
	pairs = 0;
	errors = 0;
	while (stack)
	{
		rest = stack->next;
		while (rest)
		{
			pairs++;
			if (stack->content > rest->content)
				errors++;
			rest = rest->next;
		}
		stack = stack->next;
	}
	return ((float)errors / (float)pairs);
}

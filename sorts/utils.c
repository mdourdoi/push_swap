/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:44:51 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/20 17:06:54 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt_round(int n)
{
	int	x;

	x = 0;
	while ((x + 1) * (x + 1) <= n)
		x++;
	return (x);
}

void	ft_select_rot(t_list **stack, char str_stack, int rot, int rev_rot, t_rule *rules)
{
	if (rot > rev_rot)
	{
		while (rev_rot-- > 0)
			ft_reverse_rotate(stack, str_stack, 1, rules);
	}
	else
	{
		while (rot-- > 0)
			ft_rotate(stack, str_stack, 1, rules);
	}
}

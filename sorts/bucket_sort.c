/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:58:49 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/20 17:07:18 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_switch_bucket(int *j, int size, int *step)
{
	*j = 0;
	*step += size;
}

static void	ft_fill_b(t_list **a, t_list **b, int size, t_rule *rules)
{
	int		j;
	int		step;
	int		rot;
	int		rev_rot;

	j = 0;
	step = size - 1;
	while (*a)
	{
		if (++j == size)
			ft_switch_bucket(&j, size, &step);
		rot = ft_get_first_index(*a, step - size, step);
		rev_rot = (ft_lstsize(*a) - ft_get_last_index(*a, step - size, step))
			% ft_lstsize(*a);
		if (rot >= 0)
		{
			ft_select_rot(a, 'a', rot, rev_rot, rules);
			ft_push(b, 'b', a, rules);
		}
		else
			ft_switch_bucket(&j, size, &step);
	}
}

void	ft_bucketsort(t_list **a, t_list **b, t_rule *rules)
{
	int		len;
	int		sqrt;
	int		rot;
	int		rev_rot;

	if (ft_issorted(*a))
		return ;
	set_index(*a);
	sqrt = ft_sqrt_round(ft_lstsize(*a));
	ft_fill_b(a, b, sqrt, rules);
	while (*b)
	{
		len = ft_lstsize(*b);
		rot = ft_maxpos(*b);
		rev_rot = (len - rot) % len;
		ft_select_rot(b, 'b', rot, rev_rot, rules);
		ft_push(a, 'a', b, rules);
	}
}

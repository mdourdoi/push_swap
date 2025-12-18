/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:58:49 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/20 15:05:54 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_b(t_list **a, t_list **b, int size)
{
	int		i;
	int		j;
	int		step;
	int 	rot;
	int		rev_rot;

	i = 0;
	j = 0;
	step = size;
	while (*a)
	{
		if (j++ == size)
		{
			j = 0;
			i++;
			step += size;
		}
		rot = ft_get_first_index(*a, step - size, step);
		rev_rot = ft_get_last_index(*a, step - size, step);
		ft_select_rot(a, 'a', rot, rev_rot);
		ft_push(b, 'b', a);
	}
}

static void	ft_check_bucket(t_list **a, t_list **b, int size)
{
	
}

void	ft_bucketsort(t_list **a, t_list **b)
{
	int		len;
	int		sqrt;

	len = ft_lstsize(*a);
	set_index(*a);
	sqrt = ft_sqrt_round(len);
	ft_fill_b(a, b, ft_sqrt_round(len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:58:49 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 13:49:57 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		rot = ft_get_first_index(*a, step - size, step);
		rev_rot = (ft_lstsize(*a) - ft_get_last_index(*a, step - size, step))
			% ft_lstsize(*a);
		if (rot >= 0)
		{
			ft_select_rot_a(a, rot, rev_rot, rules);
			ft_push(b, 'b', a, rules);
		}
		else
			step += size;
	}
}

/*static void	print_stack_index(t_list *lst)
{
	while (lst != NULL)
	{
		printf("content : %d index : %d\n",  lst->content, lst->index);
		lst = lst->next;
	}
}*/

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
		ft_select_rot_b(b, rot, rev_rot, rules);
		ft_push(a, 'a', b, rules);
	}
}

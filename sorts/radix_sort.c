/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:23:06 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 13:49:25 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_all_b(t_list **a, t_list **b, t_rule *rules)
{
	while (*b)
		ft_push(a, 'a', b, rules);
}

static int	ft_get_zeros(t_list *a, int k)
{
	int	ret;

	ret = 0;
	while (a)
	{
		if (!((a->index >> k) & 1))
			ret++;
		a = a->next;
	}
	return (ret);
}

#include <stdio.h>

static void	print_stack_index(t_list *lst)
{
	while (lst != NULL)
	{
		printf("content : %d index : %d\n",  lst->content, lst->index);
		lst = lst->next;
	}
}

void	ft_radix_sort(t_list **a, t_list **b, t_rule *rules)
{
	int	len;
	int	proc;
	int	k;

	len = ft_lstsize(*a);
	k = -1;
	set_index(*a);
	print_stack_index(*a);
	while (++k < 32 && !ft_issorted(*a))
	{
		proc = 0;
		while (ft_get_zeros(*a, k))
		{
			if (!(((*a)->index >> k) & 1))
				ft_push(b, 'b', a, rules);
			else
				ft_rotate(a, 'a', 1, rules);
			proc++;
		}
		ft_select_rot_a(a, len - proc,	ft_lstsize(*a) - (len - proc), rules);
		ft_push_all_b(a, b, rules);
	}
}

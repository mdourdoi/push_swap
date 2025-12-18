/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:59:07 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/20 11:50:33 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"https://profile.intra.42.fr/

static void	set_to_first(t_list **a)
{
	while (*a && (*a)->index != -1)
		*a = (*a)->next;
}

static void	set_min(t_list *a, int to_set)
{
	int 	current_min;
	t_list	*best;

	set_to_first(&a);
	best = a;
	if (a)
	{
		current_min = a->content;
		while (a)
		{
			if (a->content < current_min && a->index == -1)
			{
				best = a;
				current_min = a->content;
			}
			a = a->next;
		}
		best->index = to_set;
	}
}

void	set_index(t_list *a)
{
	int 	i;
	int 	len;

	i = -1;
	len = ft_lstsize(a);
	while (++i < len)
		set_min(a, i);
}
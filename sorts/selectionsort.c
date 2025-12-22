/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:56:33 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/20 14:48:34 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_selectionsort(t_list **a, t_list **b, t_rule *rules)
{
	int		rot;
	int		rev_rot;
	int		len;

	if (ft_issorted(*a))
		return ;
	while (*a)
	{
		rot = ft_minpos(*a);
		len = ft_lstsize(*a);
		rev_rot = (len - rot) % len;
		ft_select_rot(a, 'a', rot, rev_rot, rules);
		ft_push(b, 'b', a, rules);
	}
	while (*b)
		ft_push(a, 'a', b, rules);
}

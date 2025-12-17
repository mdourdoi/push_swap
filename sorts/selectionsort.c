/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:56:33 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/17 12:54:35 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_maxpos(t_list *a)
{
	int	max;
	int	pos;
	int	pos_max;

	max = a->content;
	pos = 0;
	pos_max = 0;
	while (a)
	{
		if (a->content > max)
		{
			max = a->content;
			pos_max = pos;
		}
		a = a->next;
		pos++;
	}
	return (pos_max);
}

void	ft_selectionsort(t_list **a, t_list **b)
{
	int		rot;
	int		rev_rot;
	int		len;

	if (ft_issorted(*a))
		return ;
	while (*a)
	{
		rot = ft_maxpos(*a);
		len = ft_lstsize(*a);
		rev_rot = (len - rot) % len;
		if (rot > rev_rot)
		{
			while (rev_rot-- > 0)
				ft_reverse_rotate(a, 'a', 1);
		}
		else
		{
			while (rot-- > 0)
				ft_rotate(a, 'a', 1);
		}
		ft_push(b, 'b', a);
	}
	while (*b)
		ft_push(a, 'a', b);
}

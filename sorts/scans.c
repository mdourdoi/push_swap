/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:14:50 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/20 17:05:55 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_minpos(t_list *a)
{
	int	min;
	int	pos;
	int	pos_min;

	min = a->content;
	pos = 0;
	pos_min = 0;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			pos_min = pos;
		}
		a = a->next;
		pos++;
	}
	return (pos_min);
}

int	ft_maxpos(t_list *a)
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

int	ft_get_first_index(t_list *a, int low, int high)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= low && a->index <= high)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

int	ft_get_last_index(t_list *a, int low, int high)
{
	int	pos;
	int	max_pos;

	pos = 0;
	max_pos = -1;
	while (a)
	{
		if (a->index >= low && a->index <= high)
			max_pos = pos;
		pos++;
		a = a->next;
	}
	return (max_pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:45:57 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/17 12:56:49 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_list *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->content > (a->next)->content)
			return (0);
		a = a->next;
	}
	return (1);
}

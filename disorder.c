/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:08:20 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/16 14:39:51 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_get_disorder(t_list *stack)
{
	long		errors;
	long		pairs;
	t_list		*rest;

	if (!stack || !stack->next)
		return (0.0);
	pairs = 0;
	errors = 0;
	while (stack)
	{
		rest = stack->next;
		while (rest)
		{
			pairs++;
			if (stack->content > rest->content)
				errors++;
			rest = rest->next;
		}
		stack = stack->next;
	}
	return ((float)errors / (float)pairs);
}

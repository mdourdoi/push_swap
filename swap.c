/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:29:41 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/16 14:03:15 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char c, int flag)
{
	t_list	*first;
	t_list	*second;
	
	if (!stack || !(*stack) || !(*stack)->next)
		return;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (flag)
		ft_printf("s%c\n", c);
}

void	ft_swap_both(t_list *a, t_list *b)
{
	ft_swap(&a, 0, 0);
	ft_swap(&b, 0, 0);
	ft_printf("ss");
}
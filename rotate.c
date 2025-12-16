/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:01:33 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/16 14:03:07 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack, char c, int flag)
{
	t_list	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	(ft_lstlast(*stack))->next = first;
	if (flag)
		ft_printf("r%c\n", c);
}

void	ft_rotate_both(t_list *a, t_list *b)
{
	ft_rotate(&a, 0, 0);
	ft_rotate(&b, 0, 0);
	ft_printf("rr");
}
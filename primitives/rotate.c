/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:01:33 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 10:21:15 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack, char c, int flag, t_rule *rule)
{
	t_list	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	(ft_lstlast(*stack))->next = first;
	if (flag)
	{
		if (rule->checker == FALSE)
			ft_printf("r%c\n", c);
		if (rule->bench == TRUE)
		{
			if (c == 'a')
				rule->operation[RA] += 1;
			else
				rule->operation[RB] += 1;
		}
	}
}

void	ft_rotate_both(t_list *a, t_list *b, t_rule *rule)
{
	ft_rotate(&a, 0, 0, rule);
	ft_rotate(&b, 0, 0, rule);
	if (rule->checker == FALSE)
		ft_printf("rr");
	else
		rule->operation[RR] += 1;
}

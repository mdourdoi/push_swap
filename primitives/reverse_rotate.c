/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:28:01 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/29 17:12:08 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **stack, char c, int flag, t_rule *rule)
{
	t_list	*last;
	t_list	*previous;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	previous = *stack;
	while (previous->next && (previous->next)->next)
		previous = previous->next;
	last = previous->next;
	previous->next = NULL;
	ft_lstadd_front(stack, last);
	if (flag)
	{
		if (rule->checker == FALSE)
			ft_printf("rr%c\n", c);
		if (rule->bench == TRUE)
		{
			if (c == 'a')
				rule->operation[RRA] += 1;
			if (c == 'b')
				rule->operation[RRB] += 1;
		}
	}
}

void	ft_reverse_rotate_both(t_list *a, t_list *b, t_rule *rule)
{
	ft_reverse_rotate(&a, 0, 0, rule);
	ft_reverse_rotate(&b, 0, 0, rule);
	if (rule->checker == FALSE)
		ft_printf("rrr");
	else
		rule->operation[RRR] += 1;
}

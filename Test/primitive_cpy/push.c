/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:48:35 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/16 14:23:27 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **stack1, char c1, t_list **stack2, t_rule *rule)
{
	t_list	*temp;

	if (!stack1 || !stack2 || !(*stack2))
		return ;
	temp = *stack2;
	*stack2 = (*stack2)->next;
	ft_lstadd_front(stack1, temp);
	if (rule->bench == FALSE)
		ft_printf("p%c\n", c1);
	else		//This is the part where the operation are registered in bench mode 
	{
		if (c1 == 'a')
			rule->operation[PA] += 1;
		if (c1 == 'b')
			rule->operation[PB] += 1;
	}
}

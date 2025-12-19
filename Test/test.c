/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:50:49 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/18 17:04:54 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "rules.h"
#include "libft_mel.h"
#include <stdio.h>

void	print_stack(t_list *lst)

{
	while (lst != NULL)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}

void	print_rules(t_rule *rule)
{
	printf("=========== RULES ============\n");
	printf("mode : %d\n", rule->mode);
	printf("bench : %d\n", rule->bench);
	printf("disorder : %.2f\n", rule->disorder);
	printf("elem : %zu\n", rule->nb_element);
	printf("==============================\n");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	**b;
	t_rule	rule;

	init_rule(&rule);
	a = parse_args(ac, av, &rule);
	rule.disorder = ft_get_disorder(a);
	print_rules(&rule);
	if (a == NULL)
	{
		printf("error");
		return (0);
	}
	printf("Init \n");
	print_stack(a);
	b = ft_calloc(1, sizeof(t_list *));
	gateway(&rule, &a, b);
	printf("final: \n");
	print_stack(a);
	print_stack(*b);
	clear_stack(a);
	clear_stack(*b);
	free(b);
	return (0);
}

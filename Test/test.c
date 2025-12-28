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

#ifdef DEBUG
void	print_stack(t_list *lst)

{
	while (lst != NULL)
	{
		print_errf("%d\n", lst->content);
		lst = lst->next;
	}
}
#endif
void	print_rules(t_rule *rule)
{
	printf("=========== RULES ============\n");
	printf("mode : %d\n", rule->mode);
	printf("bench : %d\n", rule->bench);
	printf("disorder : %.2f\n", rule->disorder);
	printf("elem : %zu\n", rule->nb_element);
	printf("==============================\n");
}

void    free_args(char **args)
{
    size_t  i;

    i = 0;
    while (args[i])
    {
        if (args[i])
            free(args[i]);
        i++;
    }
    if (args)
        free(args);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	**b;
	t_rule	rule;
    char **args;

    ac += 1;
	init_rule(&rule);
    args = harmonize_args(av);
	a = parse_args(args_len(args), args, &rule);
	rule.disorder = ft_get_disorder(a);
	print_rules(&rule);
	if (a == NULL)
	{
		printf("error");
		return (0);
	}
#ifdef DEBUG
	printf("Init \n");
	print_stack(a);
#endif
	b = ft_calloc(1, sizeof(t_list *));
	gateway(&rule, &a, b);
#ifdef DEBUG
	printf("final: \n");
	print_stack(a);
	print_stack(*b);
#endif
    if(rule.bench == TRUE) {
        display_benchmark(&rule);
    }
	clear_stack(a);
	clear_stack(*b);
    free_args(args);
	free(b);
	return (0);
}

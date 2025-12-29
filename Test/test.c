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
#include "print_errf.h"
#include "rules.h"
#include "libft_mel.h"
#include <stdio.h>

#ifdef DEBUG_MODE_
#include "debug.h"
#endif

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
#ifdef DEBUG_MODE_
    print_args(args, PUSH_SWP);
#endif
	a = parse_args(args_len(args), args, &rule);
	rule.disorder = ft_get_disorder(a);
#ifdef DEBUG_MODE_
	print_rules(&rule, PUSH_SWP);
#endif
	if (a == NULL)
	{
		printf("error");
		return (0);
	}
#ifdef DEBUG_MODE_
	printf("\x1b[32m[DEBUG]\x1b[0m Init \n");
	print_stack(a, PUSH_SWP);
#endif
	b = ft_calloc(1, sizeof(t_list *));
	gateway(&rule, &a, b);
#ifdef DEBUG_MODE_
	printf("\x1b[32m[DEBUG]\x1b[0m final: \n");
	print_stack(a, PUSH_SWP);
	print_stack(*b, PUSH_SWP);
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

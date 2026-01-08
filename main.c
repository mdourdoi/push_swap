/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:31:03 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/08 15:09:56 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"
#include "push_swap.h"

t_list	*init_program(char **av, t_rule *rules)
{
	char	**args;
	t_list	*a;

	a = NULL;
	args = harmonize_args(av);
	init_rule(rules);
	rules->checker = FALSE;
	a = parse_args(args_len(args), args, rules);
	rules->disorder = ft_get_disorder(a);
	if (args != NULL)
		free_args(args);
	return (a);
}

void	exit_program(t_list *a, t_list **b)
{
	if (ft_issorted(a) != 1)
		panic_exit(&a, b, NULL);
	clear_stack(a);
	clear_stack(*b);
	free(b);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_rule	rules;
	t_list	*a;
	t_list	**b;

	if (ac < 2)
		return (0);
	b = ft_calloc(1, sizeof(t_list *));
	if (!b)
		return (0);
	a = init_program(av, &rules);
	if (a == NULL)
		panic_exit(&a, b, NULL);
	if (rules.disorder > 0)
		gateway(&rules, &a, b);
	if (rules.bench == TRUE)
		display_benchmark(&rules);
	exit_program(a, b);
	return (0);
}

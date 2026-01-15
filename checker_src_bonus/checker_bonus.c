/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:55:45 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/15 15:49:16 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_list	*init_checker(char **av, t_rule *rules)
{
	char	**args;
	t_list	*a;

	a = NULL;
	args = harmonize_args(av);
	init_rule(rules);
	rules->checker = TRUE;
	a = parse_args(args_len(args), args, rules);
	if (args != NULL)
		free_args(args);
	return (a);
}

t_bool	check_stack_b(t_list *b)
{
	if (b == NULL)
		return (TRUE);
	else
		return (FALSE);
}

void	processing(t_list **a, t_list **b, t_rule *rules)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		check_op(op, a, b);
		execute(op, a, b, rules);
		if (op)
			free(op);
		op = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_rule	rules;
	t_list	*a;
	t_list	**b;

	if (argc < 2)
		return (0);
	b = ft_calloc(1, sizeof(t_list *));
	if (!b)
		return (0);
	a = init_checker(argv, &rules);
	if (a == NULL || rules.bench || rules.flags)
	{
		drain_pipe();
		panic_exit(&a, b, NULL, rules.is_valid * (1 - rules.bench)
			* (1 - rules.flags));
	}
	processing(&a, b, &rules);
	if ((check_stack_b(*b) == TRUE) && (ft_issorted(a) == 1))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stack(a);
	clear_stack(*b);
	free(b);
	return (0);
}

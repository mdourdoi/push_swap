/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:55:45 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/07 14:02:44 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "rules.h"
#include "checker.h"
#include "print_errf.h"

void	free_args(char **args)
{
	size_t	i;

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

t_list	*init_checker(char **av, t_rule *rules)
{
	char	**args;
	t_list	*a;

	a = NULL;
	args = harmonize_args(av);
	init_rule(rules);
	rules->checker = TRUE;
	a = parse_args(args_len(args), args, rules);
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

	argc++;
	a = NULL;
	b = ft_calloc(1, sizeof(t_list *));
	if (argc > 2)
	{
		a = init_checker(argv, &rules);
		if (a == NULL)
		{
			drain_pipe();
			panic_exit(&a, b, NULL, PRINT_ERROR);
		}
		processing(&a, b, &rules);
		if ((check_stack_b(*b) == TRUE) && (ft_issorted(a) == 1))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	clear_stack(a);
	clear_stack(*b);
	free(b);
	return (0);
}

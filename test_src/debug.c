/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:29:02 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 11:29:04 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_stack(t_list *lst, char *mode)
{
	while (lst != NULL)
	{
		print_errf("\x1b[32m[DEBUG]\x1b[0m %s stack : %d\n", mode, lst->content);
		lst = lst->next;
	}
}

void    print_args(char **args, char *mode)
{
    size_t  i;

    i = 0;
    while (args[i] != NULL)
    {
        print_errf("\x1b[32m[DEBUG]\x1b[0m %s args : %s\n", mode, args[i]);
        i++;
    }
}

void    print_op_dbg(char *op, char *mode)
{
    print_errf("\x1b[32m[DEBUG]\x1b[0m %s op : %s\n", mode, op);
}

void	print_rules(t_rule *rule, char *mode)
{
	print_errf("\x1b[32m[DEBUG]\x1b[0m %s =========== RULES ============\n", mode);
	print_errf("\x1b[32m[DEBUG]\x1b[0m %s mode : %d\n", mode, rule->mode);
	print_errf("\x1b[32m[DEBUG]\x1b[0m %s bench : %d\n", mode, rule->bench);
	print_errf("\x1b[32m[DEBUG]\x1b[0m %s disorder : %.2f\n", mode, rule->disorder);
	print_errf("\x1b[32m[DEBUG]\x1b[0m %s elem : %zu\n", mode, rule->nb_element);
	print_errf("\x1b[32m[DEBUG]\x1b[0m %s ==============================\n", mode);
}

#ifndef CHECKER_H
# define CHECKER_H

#include "get_next_line.h"
#include "rules.h"
#include "push_swap.h"
#include "ft_printf.h"


void    panic_exit(t_list **a, t_list **b, char *op);
void    check_error(t_list **a, t_list **b, char *op);
void    panic_exit(t_list **a, t_list **b, char *op);
void    execute(char *op, t_list **a, t_list **b, t_rule *rules);

#endif

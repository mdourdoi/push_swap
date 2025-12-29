#include "checker.h"
#include "print_errf.h"
#include "rules.h"

void    panic_exit(t_list **a, t_list **b, char *op)
{
    print_errf("error\n");
    clear_stack(*a);
    clear_stack(*b);
    if (op != NULL)
        free(op);
    exit(EXIT_FAILURE);
}

void    check_error(t_list **a, t_list **b, char *op)
{
        if (ft_strcmp(op, "error\n") == 0)
            panic_exit(a, b, op);
}

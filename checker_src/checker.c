#include "get_next_line.h"
#include "rules.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


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

void    init_checker(t_list *a, char **av, t_rules *rules)
{
    char    **args;

    args = harmonize_args(argv);
    init_rule(&rules)
    rules->checker = true;
	a = parse_args(args_len(args), args, &rules);
    free_args(args);
}

int main(int argc, char **argv)
{
    char *op;
    t_rule  rules;
    t_list  *a;
    t_list  **b;

    
    init_checker(a, argv, &rules);
    op = get_next_line(0);
    printf("%d - ", i);
    printf("%s", op);
    while(op)
    {
        i++;
        if (op)
            free(op);
        op = get_next_line(0);
        if (op) {
            execute_op(&a, b, &rules, op);
            printf("%d - ", i);
            printf("%s", op);
        }
    }
    return (0);
}

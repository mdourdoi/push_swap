#include "get_next_line.h"
#include "rules.h"
#include "checker.h"
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

t_list    *init_checker(char **av, t_rule *rules)
{
    char    **args;
    t_list  *a;

    a = NULL;
    args = harmonize_args(av);
    init_rule(rules);
    rules->checker = true;
	a = parse_args(args_len(args), args, rules);
    free_args(args);
    return (a);
}

t_bool  check_stack_b(t_list *b)
{
    if (b == NULL)
        return (TRUE);
    else
        return (FALSE);
}

int main(int argc, char **argv)
{
    char *op;
    t_rule  rules;
    t_list  *a;
    t_list  **b;
    int fd;
    //void (*functions[10]) (t_list **a, t_list **b, t_rule *rules);

    fd = open("sample.txt", O_RDONLY);
    argc++; 
    a = NULL;
	b = ft_calloc(1, sizeof(t_list *));
    a = init_checker(argv, &rules);
   // init_table(functions);

    op = get_next_line(fd);
    check_error(&a, b, op);
    //functions[get_index(op)] (a, b, rules);
    execute(op, &a, b, &rules);
    while(op)
    {
        if (op)
            free(op);
        op = get_next_line(fd);
        if (op) {
            check_error(&a, b, op);
            //functions[get_index(op)] (a, b, rules);
            execute(op, &a, b, &rules);
        }
    }
    if ((check_stack_b(*b) == TRUE) && (ft_issorted(a) == 1))
        ft_printf("OK\n");
    return (0);
}

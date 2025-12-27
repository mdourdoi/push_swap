#include "push_swap.h"
#include "checker.h"

void    push_a(t_list **a, t_list **b, t_rule *rules)
{
    ft_push(a, '\0', b, rules);
}

void    push_b(t_list **a, t_list **b, t_rule *rules)
{
    ft_push(b, '\0', a, rules);
}

void    swap(t_list **a, t_rule *rules)
{
    ft_swap(a, '\0', 0, rules);  
}

void    execute(char *op, t_list **a, t_list **b, t_rule *rules)
{
    if (ft_strcmp(op, "pa\n") == 0)
        push_a(a, b, rules);
    if (ft_strcmp(op, "pb\n") == 0)
        push_b(a, b, rules);
    if (ft_strcmp(op, "sa\n") == 0)
        swap(a, rules);
    if (ft_strcmp(op, "sb\n") == 0)
        swap(b, rules);
    if (ft_strcmp(op, "ra\n") == 0)
        rotate(a, rules);
    if (ft_strcmp(op, "rb\n") == 0)
        rotate(b, rules);
    if (ft_strcmp(op, "rr\n") == 0)
        ft_rotate_both(*a, *b, rules);
    if (ft_strcmp(op, "rra\n") == 0)
        reverse_rotate(a, rules);
    if (ft_strcmp(op, "rrb\n") == 0)
        reverse_rotate(b, rules);
    if (ft_strcmp(op, "rrr\n") == 0)
        ft_reverse_rotate_both(*a, *b, rules);
}

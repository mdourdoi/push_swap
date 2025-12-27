#include "push_swap.h"
#include "checker.h"
void    rotate(t_list **a, t_rule *rules)
{
    ft_rotate(a, '\0', 0, rules);
}

void    reverse_rotate(t_list **a, t_rule *rules)
{
    ft_reverse_rotate(a, '\0', 0, rules);
}

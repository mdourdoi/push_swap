int push_section(t_list **a, t_list **b, t_rule *rules, char *op)
{
    if (ft_strcmp(op, "pa\n") == 0)
        ft_push(a, '\0', b, rule);
    else 
        ft_push(b, '\0', a, rule);
    return (1);
}

int get_value(char *key)
{
    size_t  i;
    int value;

    i = 0;
    value = 0;
    while(key[i])
    {
        value += key[i] % 10;
        i++;
    }
    if ((value % 10) == 9)
        value -= 1;
    return (value);
}
int execute_op(t_list **a, t_list **b, t_rule *rules, char *op)
{
        
        panic_exit(a, b, op);
}

void    init_table( void (*array[9]) (t_list **a, t_list **b, t_rule *rules))
{
    array[0] = ft_swap_both;
    array[1] = reverse_rotate_b;
    array[2] = reverse_rotate_a;
    array[3] = rotate_a;
    array[4] = push_b;
    array[5] = push_a;
    array[6] = swap_b;
    array[7] = rotate_b;
    array[8] = swap_a;
    array[9] = ft_reverse_rotate_both;
}

int hash(char *key)
{
    size_t  i;
    int value;

    i = 0;
    value = 0;
    while(key[i])
    {
        value += key[i];
        value = ((value^(key[2])) & 0xdfff) % 11;
        i++;
    }
    if (value >= 10)
        return (value - 1);
    return (value);
}

int get_index(char *op)
{
    if (op[0] == 's')
    {
        if (op[1] == 'a')
            return (2);
        else 
            return (4);
    }
    return (hash(op));
}

#include "ft_printf.h"
#include "libft.h"

static void    set_res(char *res)
{
    size_t  i;

    i = 0;

    while (i < 5)
    {
        res[i] = '0';
        i++;
    }
    res[i] = '\0';
}

static void    recursion(int nb, char *res, int index, int count)
{
    if (count == 2)
    {
        res[index] = '.';
        recursion(nb, res, index - 1, count + 1);
        return ;
    }
    if (nb >= 10)
    {
        res[index] = (nb % 10) + '0';
        recursion(nb/10, res, index - 1, count + 1);
        return ;
    }
    res[index] = nb + '0';
}

int print_float(float nb)
{
    char    res[6];
    int nbr;

    nbr = nb * 10000;
    set_res(res);
    
    if (nb == 1)
        return (ft_putstr("100.00%"));
    if (nbr == 0)
        return (ft_putstr("00.00"));
    recursion(nbr, res, 4, 0);
    return (ft_putstr(res));

}

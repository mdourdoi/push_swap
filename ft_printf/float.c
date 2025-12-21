#include "ft_printf.h"
// print_float : 
//
//      this function only work for this project (float number)
//          with 2 digits max after the '.'
//      So don't use it as a real float converter (because it's hard af)
//      return the number of char print by the function

int    print_float(float nbr)
{
    int res;
    int count;

    res = nbr * 100;
    if (res < 100)
        count = ft_putstr("0.");
    else 
        count = ft_putstr("1.");
    if (res > 0)
        count += ft_putnb(res, "0123456789", 10);
    else
        count = ft_putstr("00");
    return(count);
}


#include "libft_mel.h"
#include <unistd.h>

// Print error : 
//
//      This function print a string into stderror

void    print_error(char *str)
{
    write(2, str, ft_strlen(str));
    exit(EXIT_FAILURE);
}

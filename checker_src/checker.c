#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char *str;
    int i = 0;

    str = get_next_line(0);
    printf("%d - ", i);
    printf("%s", str);
    while(str)
    {
        i++;
        if (str)
            free(str);
        str = get_next_line(0);
        if (str) {
            printf("%d - ", i);
            printf("%s", str);
        }
    }
    return (0);
}

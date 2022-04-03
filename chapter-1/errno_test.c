#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for(errno = 1; errno < 128; ++errno)
        perror("errno is: ");
    exit(0);
}
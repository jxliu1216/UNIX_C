/*
 * test the size of pipe
 *
 * Author: Jinxue liu
 * Date: 2022-04--8
 */

#include "../apue.h"

int main(void)
{
    int fd[2];
    int err;
    int cnt = 0;

    err = pipe(fd);
    if(err < 0)
    {
        err_sys("pipe error");
    }

    /* when pip is full, write will be blocked */
    while(1)
    {
        write(fd[1], "a", 1);
        ++cnt;
        printf("%d\n", cnt);
    }

    exit(1);
}
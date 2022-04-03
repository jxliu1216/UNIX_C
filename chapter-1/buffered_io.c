/*
 * using buffered I/O, e.g. getc() and putc()
 * 
 * Author: Jinxue Liu
 * Date: 2022-03-28
 */

#include "../apue.h"

int main(void)
{
    char ch;

    while((ch = getc(stdin)) != EOF)
    {
        if(putc(ch, stdout) == EOF)
        {
            err_sys("output error");
        }
    }

    if(ferror(stdin))
    {
        err_sys("input error.");
    }

    exit(0);
}
/*
 * display all arguments in terminal
 *
 * Author: Jinxue Liu
 * Date: 2022-03-30
 */

#include "../apue.h"

int main(int argc, char * argv[])
{
    int i;

    for(i = 0; argv[i] != NULL; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    exit(0);
}
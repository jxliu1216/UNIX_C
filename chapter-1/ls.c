/*
 * A simple realization of ls
 * 
 * Author: Jinxue Liu
 * Date: 2022-03-26
 * 
 */

#include "../apue.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc != 2)
    {
        err_quit("usage: ls [directory name]");
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        err_sys("can't open %s", argv[1]);
    }
    dirp = readdir(dp);
    while (dirp != NULL)
    {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);

    exit(0);
}
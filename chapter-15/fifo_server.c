/*
 * fifo_server.c:
 * using fifo to realize ipc
 * 
 * Author: Jinxue Liu
 * Date: 2022-04-09
 */

#include "../apue.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>

#define FIFO_PATH "/home/jxliu/workspace/myfifo"

int main(void)
{
    int err;
    int fifo_fd;
    char msg[MAXLINE];

    err = mkfifo(FIFO_PATH, 0777);
    if(err != 0)
    {
        err_sys("mkfifo error");
    }

    fifo_fd = open(FIFO_PATH, O_WRONLY);    /* open as write end */
    if(fifo_fd < 0)
    {
        err_sys("open error");
    }

    while(1)
    {
        printf("Input Message: ");
        fgets(msg, MAXLINE, stdin);
        write(fifo_fd, msg, strlen(msg));
    }

    err = close(fifo_fd);
    if(err != 0)
    {
        err_sys("close error");
    }
    
    exit(1);
}
/*
 * fifo_client.c:
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

    fifo_fd = open(FIFO_PATH, O_RDONLY);    /* open as read end */
    if(fifo_fd < 0)
    {
        err_sys("read error");
    }

    while(1)
    {
        printf("Show Message: ");
        read(fifo_fd, msg, MAXLINE);
        printf("%s", msg);
    }

    err = close(fifo_fd);
    if(err != 0)
    {
        err_sys("close error");
    }
    
    exit(1);
}
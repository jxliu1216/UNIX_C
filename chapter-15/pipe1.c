/*
 * using pipe
 *
 * Author: Jinxue Liu
 * Date: 2022-04-06
 */

#include "../apue.h"
#include <signal.h>

int main(void)
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    signal(SIGPIPE, SIG_IGN);

    if(pipe(fd) < 0)
    {
        err_sys("pipe error");
    }
    if((pid = fork()) < 0)
    {
        err_sys("fork eror");
    }
    else if(pid > 0)     /* parent */
    {
        close(fd[0]);    /* close read port */
        n = write(fd[1], "hello", 5);
        if(n < 0) err_sys("write error");
        sleep(5);
        n = write(fd[1], "world\n", 6);
        if(n < 0) err_sys("write error");
    }
    else                 /* child */
    {
        close(fd[1]);    /* close write port */
        n = read(fd[0], line, 11);
        printf("%s", line);
    }

    printf("This is pid: %d, parent pid: %d\n", getpid(), getppid());

    exit(0);
}
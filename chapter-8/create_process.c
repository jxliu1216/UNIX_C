/*
 * create a new process using fork()
 *
 * Auhtor: Jinxue Liu
 * Date: 2022-04-02
 */

#include "../apue.h"

int globalVal = 6;
char buf[] = "a write to stdout\n";

int main(void)
{
    int var;
    pid_t pid;

    var = 88;
    if(write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
    {
        err_sys("write error");
    }
    printf("before fork\n");

    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid == 0)
    {
        globalVal++;
        var++;
    }
    else
    {
        sleep(2);
    }

    printf("pid = %d, glob = %d, var = %d\n", getpid(), globalVal, var);

    exit(0);
}
/*
 * definition of functions declared in apue.h
 *
 * Author: Jinxue Liu
 * Date: 2022-03-26
 * 
 */

#include "apue.h"
#include <errno.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>


static void err_doit(int, int, const char *, va_list);

/*
 * Print the terminate status of process
 */
void pr_exit(int status)
{
    if(WIFEXITED(status))
    {
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    }
    else if(WIFSIGNALED(status))
    {
        printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
        #ifdef WCOREDUMP
            WCOREDUMP(status) ? " (core file generated) " : "");
        #else
            "");
        #endif
    }
    else if(WIFSTOPPED(status))
    {
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
    }
}

/*
 * Nonfatal error related to a syetem call
 * Print a message and return
 */
void err_ret(const char * fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
}

/* 
 * Fatal error related to a system call.
 * Print a message and terminate
 */
void err_sys(const char * fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}

/*
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
void err_quit(const char * fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    err_doit(0, 0, fmt, ap);
    va_end(ap);
    exit(1);
}

/*
 * Print a message and return to caller
 * Caller specifies "errnoflag"
 */
static void err_doit(int errnoflag, int error, const char * fmt, va_list ap)
{
    char buf[MAXLINE];

    vsnprintf(buf, MAXLINE-1, fmt, ap);
    if(errnoflag)
    {
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s", strerror(error));
    }
    strcat(buf, "\n");
    fflush(stdout);            /* in case stdout and stderr are the same */
    fputs(buf, stderr);
    fflush(NULL);              /* flushes all stdio output streams */
}
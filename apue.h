/*
 * include some common variables and prototype of some common functions
 * 
 * Author: Jinxue Liu
 * Date: 2022-03-26
 * 
 */

#ifndef _APUE_H_
#define _APUE_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#define MAXLINE 4096                    /* max line length */

/* PROCESS */
void pr_exit(int);

/* ERROR */
void err_quit(const char * fmt, ...) __attribute__((noreturn));
void err_sys(const char * fmt, ...) __attribute__((noreturn));
void err_ret(const char * fmt, ...);

#endif /* _APUE_H_ */
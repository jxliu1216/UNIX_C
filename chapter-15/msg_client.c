/*
 * msg_client.c:
 * ipc using message queue, client end
 * 
 * Author: Jinxue Liu
 * Date: 2022-04-10
 */

#include "../apue.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PATH "./msg_server.c"
#define MSGSIZE 512

typedef struct mymsg {
    long mtype;
    char mtext[MSGSIZE];
} MYMSG;

int main(void)
{
    int msg_id;
    MYMSG msg;

    key_t key = ftok(PATH, 123);
    msg_id = msgget(key, IPC_CREAT | 0666);
    if(msg_id == -1)
    {
        err_quit("message queue error");
    }

    while(1)
    {
        if(msgrcv(msg_id, (void*)&msg, MSGSIZE, 1, 0) < 0)
        {
            err_quit("message receive error");
        }
        printf("data is: %s", msg.mtext);

        if(strncmp(msg.mtext, "QUIT", 4) == 0) break;
    }

    exit(0);
}
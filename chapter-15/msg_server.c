/*
 * msg_server.c:
 * ipc using message queue, service end
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
        char msg_info[MSGSIZE];
        memset(msg_info, 0, sizeof(msg_info));
        msg.mtype = 1;
        printf("input message: ");
        fgets(msg_info, sizeof(msg_info), stdin);
        strcpy(msg.mtext, msg_info);

        if(msgsnd(msg_id, (void*)&msg, MSGSIZE, 0) < 0)
        {
            err_quit("message send error");
        }

        if(strncmp(msg_info, "QUIT", 4) == 0) break;
    }

    if(msgctl(msg_id, IPC_RMID, NULL) < 0)
    {
        err_quit("message queue remove error");
    }

    exit(0);
}
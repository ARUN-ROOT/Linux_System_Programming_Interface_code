/************************************************************************************************************/
/* Name			: messageQueuesender.c                        */	   
/* Date			: 1/3/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			          */
/* o/p				: 



*/
                                                                                        
/************************************************************************************************************/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct mymsg_buf
{
  long msg_type;
  char msg_text[200];
};

int main()
{
  int msgid;
  char str[]="msg1: Arun";
  struct mymsg_buf my_dtl;
  
  int msg_len=strlen(str);
  
  my_dtl.msg_type = 2;
  strncpy(my_dtl.msg_text,str,msg_len);
  
  //int msgget(key_t key, int msgflg);
  msgid=msgget(72,0664|IPC_CREAT);
  perror("msgget");
  
  //int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
  msgsnd(msgid,&my_dtl,msg_len,1);
  perror("msgsnd");
  
    
}



























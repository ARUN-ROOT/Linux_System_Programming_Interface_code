/************************************************************************************************************/
/* Name			: messageQueuereceiver.c                        */	   
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
  ssize_t rec_bytes;
  
  struct mymsg_buf my_dtl;
  
   //int msgget(key_t key, int msgflg);
  msgid=msgget(72,0664|IPC_CREAT);
  perror("msgget");
  
  //ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,int msgflg);
  rec_bytes=msgrcv(msgid,&my_dtl,200,0,1);
  perror("msgrcv");
  
  printf("msgid = %ld \n",my_dtl.msg_type);
  
  write(1,my_dtl.msg_text,rec_bytes);
  
    
}



























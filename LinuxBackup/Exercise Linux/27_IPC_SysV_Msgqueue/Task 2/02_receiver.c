/************************************************************************************************************/
/* Name			: messageQueueReceiver.c                        */	   
/* Date			: 1/3/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			          */
/* o/p				: 



*/
                                                                                        
/************************************************************************************************************/
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>

struct mymsg_buf
{
  long msg_type;
  char msg_text[200];
};

int main()
{
  int msgid;
  key_t key;
  struct mymsg_buf msg;
  ssize_t numread;
  
  key=ftok("msgq",72);
  
  if(key==-1)
  {
    perror("client :ftok() failed to create Unique Key\n");
    exit(-1);
  }  
  
  printf("client :system V IPC u_key %u \n",key);
  
  msgid=msgget(key,0664|IPC_CREAT);
  if(msgid==-1)
  {
    perror("client: msgget failed to create msg queue id \n");
    exit(-1);
  }
  
  printf("client: message queue id %d \n",msgid);
  
  if((numread=msgrcv(msgid,&msg,sizeof msg.msg_text,1,0))==-1)
  {
    perror("client:msgrcv failed ");
  }
  else
    write(1,msg.msg_text,numread);
    
  //attempt to read msg queue again
   if((numread=msgrcv(msgid,&msg,sizeof msg.msg_text,1,0))==-1)
  {
    perror("client:msgrcv failed ");
  }
  else
    write(1,msg.msg_text,numread);
    
  
}





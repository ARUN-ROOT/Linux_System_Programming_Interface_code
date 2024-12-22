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
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct mymsg_buf
{
  long msg_type;
  char msg_text[200];
};

int main()
{
  key_t key;
  int msgid,msg_len;
  
  struct mymsg_buf msg;
  char str[]="msg1: Arun Welcome";
  
  key=ftok("msgq",72);
  
  if(key==-1)
  {
    perror("server:ftok() failed to create Unique Key\n");
    exit(-1);
  }  
  
  printf("Server:system V IPC key u_key %u \n",key);
  
  msgid=msgget(key,0664|IPC_CREAT);
  if(msgid==-1)
  {
    perror("server : msgget failed to create msg queue id \n");
    exit(-1);
  }
  
  printf("server: message queue id %d \n",msgid);
  
  msg_len=strlen(str);
  
  strncpy(msg.msg_text,str,msg_len);
  msg.msg_type=1;
  
  if(msgsnd(msgid,&msg,msg_len,0)==-1)
  {
    perror("server: failed to send msg");
    exit(-1);
  }
  
  printf("server:message send successfully \n");
  printf("server : waiting (10 sec .) for client ...\n");
  sleep(10);
  printf("server: removing msg queue \n");
  
  if(msgctl(msgid,IPC_RMID,NULL)==-1)
  {
    perror("server:msg ctrl");
    exit(-1);
  }
  printf("server : msg queue removed successfully \n");
}












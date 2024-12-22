/************************************************************************************************************/
/* Name			: systemVs_sharedmemory.c                                    */	   
/* Date			: 8/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: process2	*/
/*			                                                                                     */
/* o/p				: 

arun@arun:~/practise$ ./process1
shmget(): Success
shared memory content 	:Arun welcome to shared memory
shared memory content 	:Arun welcome to shared memory
shared memory content 	:Arun welcome to shared memory
shared memory content 	:Arun welcome to shared memory
shared memory content 	:Arun welcome to shared memory
shared memory content 	:Arun welcome to shared memory
shared memory content 	:Arun welcome to shared memory
shared memory content 	:Arun welcome to shared memory
shared memory content 	:Arun welcome to shared memory
shared memory content 	:Arun welcome to shared memory
arun@arun:~/practise$ 


*/
                                                                                        
/************************************************************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(int argc,char *argv[])
{
  key_t key;
  int shmget_id;
  char *ptr;
  
  //key_t ftok(const char *pathname, int proj_id);
  key=ftok("shm_keyfile",85);
  
  //int shmget(key_t key, size_t size, int shmflg);
  shmget_id=shmget(key,2048,IPC_CREAT);
  perror("shmget()");
  for(int i=0;i<10;i++)
  {
    //void *shmat(int shmid, const void *shmaddr, int shmflg);
    ptr=(char*)shmat(shmget_id,NULL,0);
     sleep(2);
    printf("shared memory content \t:%s\n",ptr);
    //sleep(2);
  
  }
  
  //int shmdt(const void *shmaddr);
  shmdt(ptr);
  
  
}

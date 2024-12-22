/************************************************************************************************************/
/* Name			: systemVs_sharedmemory.c                                    */	   
/* Date			: 11/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: process1	*/
/*			           In shmget permission is must                        
                                  otherwise you get error segmentation fault because writing permission not given
                                  same keyfile and Number are used onotherside 
                                  shmid_ds structure access*/
/* o/p				: In this code practise.c write something on shared memory
                                 process1.c and process2.c read content in shared memory.
                                 so,process1 and process2 finally sucesss to read content while other process trying to read.
                                 to avoid mutually read use semaphore key


*/
                                                                                        
/************************************************************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>




int main(int argc,char *argv[])
{
  key_t key;
  int shmget_id;
  char *ptr;
  char *str="Arun welcome to shared memory";
  
  //key_t ftok(const char *pathname, int proj_id);
  key=ftok("shm_keyfile",85);
  
  //int shmget(key_t key, size_t size, int shmflg);
  shmget_id=shmget(key,2048,IPC_CREAT|0666);
  perror("shmget()");
  
  printf("shmget_id\t %d\n",shmget_id);
  
  //void *shmat(int shmid, const void *shmaddr, int shmflg);
  ptr=(char*)shmat(shmget_id,NULL,SHM_RND);
  perror("shmat()");
  
  strcpy(ptr,str);
  shmdt(ptr);
  
  

}
 

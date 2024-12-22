/************************************************************************************************************/
/* Name			: systemVs_semapphore process2.c                                    */	   
/* Date			: 15/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: process2	*/
/*			                                                                                     */
/* o/p				: 



*/
                                                                                        
/************************************************************************************************************/


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


int main(int argc,char *argv[])
{

  key_t key;
  int semget_id;
  int fd;
  ssize_t numread;
  char arr[1024];
  
  struct sembuf my_sem;
  my_sem.sem_num=2;
  my_sem.sem_op=-1;
  
  //key_t ftok(const char *pathname, int proj_id);
  key=ftok("sem_key",10);
  
  //int semget(key_t key, int nsems, int semflg);
  semget_id=semget(key,3,IPC_CREAT);
  perror("semget()"); //give exit(-1)
  
  
  
  //int semop(int semid, struct sembuf *sops, size_t nsops);
  semop(semget_id,&my_sem,1);
  perror("semop()");
  /*******************************************Reading_file*******************************************************/
  fd=open("SEM.txt",O_CREAT);
  if(fd==-1)
  {
    perror("open()");
    exit(-1);
  }
  sleep(1);
  /***************************************************************************************************************/
  numread=read(fd,arr,1024);
  printf("%s\n",arr);
  for(int i=0;i<20;i++)
  {
    printf("%d PID %d\n",i,getpid());
    sleep(1);
  }
  
  my_sem.sem_op=1;
  semop(semget_id,&my_sem,1);
  perror("semop()");
  
   if (semctl(semget_id, 2, IPC_RMID) == -1) 
    {
        perror("semctl");
        exit(1); 
    }
  return 0;
}
 

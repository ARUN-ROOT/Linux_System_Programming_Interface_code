/************************************************************************************************************/
/* Name			: systemVs_mainsemaphore.c                                    */	   
/* Date			: 15/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: mainprocess1	*/
/*			          */
/* o/p				: semaphore 

*/
                                                                                        
/************************************************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  ssize_t numwrite;
  char *str="welcome_Arun_another_one";
  
  struct sembuf my_sem;
  my_sem.sem_num=2;
  my_sem.sem_op=-1;
  
  /*Create file sem_key*/
  //key_t ftok(const char *pathname, int proj_id);
  key=ftok("sem_key",10);
  
  //int semget(key_t key, int nsems, int semflg);
  semget_id=semget(key,3,IPC_CREAT|0644);
  perror("semget()");
  
  
  //int semctl(int semid, int semnum, int cmd, ...);
  semctl(semget_id,2,SETVAL,1);//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< changed 2 --> 1
  perror("semctl()");
  
  //int semop(int semid, struct sembuf *sops, size_t nsops);
  semop(semget_id,&my_sem,1);
  perror("semop()");  /**************************************writing file**********File implementation***********************/
  fd=open("SEM.txt",O_CREAT|O_WRONLY,S_IRWXG|S_IRWXO|S_IRWXU);
  if(fd==-1)
  {
    perror("open()");
    exit(-1);
  }
  
  sleep(1);
  
  numwrite=write(fd,str,strlen(str));
  if(numwrite==-1)
  {
    perror("write()");
    exit(-1);
  }
  /******************************************************************************************************************************/
  sleep(1);
  for(int i=0;i<20;i++)
  {
    printf("%d PID %d\n",i,getpid());
    sleep(1);
  }
  /****************************************************************************************************************/
  my_sem.sem_op=1;
  semop(semget_id,&my_sem,1);
  perror("semop()");
  close(fd);
  
  return 0;
}
 

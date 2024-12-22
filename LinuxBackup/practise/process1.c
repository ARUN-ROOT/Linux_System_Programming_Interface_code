/************************************************************************************************************/
/* Name			: systemVs_semapphore process2(sharedmemory).c                                    */	   
/* Date			: 19/2/2023                                                                 */
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
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>


int main(int argc,char *argv[])
{

  key_t key,shm_key;
  int semget_id,shmget_id;
  char *ptr;
  
  struct sembuf my_sem;
  my_sem.sem_num=2;
  my_sem.sem_op=-1;
  
  //key_t ftok(const char *pathname, int proj_id);
  key=ftok("sem_key",10);
  
  //int semget(key_t key, int nsems, int semflg);
  semget_id=semget(key,3,IPC_CREAT);
  perror("semget()");
  
 
  
  //int semop(int semid, struct sembuf *sops, size_t nsops);
  semop(semget_id,&my_sem,1);
  perror("semop()");
  /**********************************************shared memory implementation**************************************/
  shm_key=ftok("shm_keyfile",25);
  
  shmget_id=shmget(shm_key,2048,IPC_CREAT);
  
  ptr=(char*)shmat(shmget_id,NULL,0);
  
  printf("shared memory data %s \n",ptr);
  
  sleep(1);
  shmdt(ptr);
  sleep(1);
  /****************************************************************************************************************/  
  
  for(int i=0;i<20;i++)
  {
    printf("%d PID %d\n",i,getpid());
    sleep(1);
  }
  
  my_sem.sem_op=1;
  semop(semget_id,&my_sem,1);
  perror("semop()");
  return 0;
}
 

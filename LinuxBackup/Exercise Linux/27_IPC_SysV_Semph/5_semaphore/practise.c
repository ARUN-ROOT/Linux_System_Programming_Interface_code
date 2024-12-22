/************************************************************************************************************/
/* Name			: systemVs_mainsemaphore(sharedmemory).c                                    */	   
/* Date			: 19/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: mainprocess1	*/
/*			          */
/* o/p				: semaphore 

*/
                                                                                        
/************************************************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>


int main(int argc,char *argv[])
{

  key_t key,shm_key;
  int semget_id,shmget_id;
  char *str="Arun in Dharmapuri\n";
  char *ptr;
  
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
  semctl(semget_id,2,SETVAL,1);///////////////************************* changed to 1
  perror("semctl()");
  
  //int semop(int semid, struct sembuf *sops, size_t nsops);
  semop(semget_id,&my_sem,1);
  perror("semop()");
  /*****************************************************Shared memory implementation************************/
  shm_key=ftok("shm_keyfile",25);
  shmget_id=shmget(shm_key,2048,IPC_CREAT|0644);
  perror("shmget()");
  
  printf("shmid :%d\n",shmget_id);
  
  ptr=(char*)shmat(shmget_id,NULL,SHM_RND);
  perror("shmat()");
  
  strcpy(ptr,str);
  
  sleep(1);
  shmdt(ptr);
  sleep(1);
  /*************************************************************************************************************/
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
 

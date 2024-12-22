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
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


int main(int argc,char *argv[])
{

  key_t key;
  int semget_id;
  
  struct sembuf my_sem[3];
  my_sem[2].sem_num=2;
  my_sem[2].sem_op=-1;
  
  my_sem[1].sem_num=1;
  my_sem[1].sem_op=-1;
  
  //key_t ftok(const char *pathname, int proj_id);
  key=ftok("sem_key",10);
  
  //int semget(key_t key, int nsems, int semflg);
  semget_id=semget(key,3,IPC_CREAT);
  perror("semget()");
  
 
  
  //int semop(int semid, struct sembuf *sops, size_t nsops);
  semop(semget_id,&my_sem[1],1);
  perror("semop()");
  
  for(int i=0;i<20;i++)
  {
    printf("%d sem 1 PID %d\n",i,getpid());
    sleep(1);
  }
  
  my_sem[2].sem_op=1;
  my_sem[1].sem_op=1;
  semop(semget_id,&my_sem[2],1);
  perror("semop()");
  
  return 0;
}
 

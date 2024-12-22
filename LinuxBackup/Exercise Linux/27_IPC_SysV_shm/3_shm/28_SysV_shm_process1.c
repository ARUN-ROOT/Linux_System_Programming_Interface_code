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
/* o/p				: 


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
  char *str="Arun,Welcome to SystemVIPC";
  
  struct shmid_ds buf;
  
  struct ipc_perm usershm_perm={0,1030,25};
  
  //key_t ftok(const char *pathname, int proj_id);
  key=ftok("shm_keyfile",55);
  
  //int shmget(key_t key, size_t size, int shmflg);
  shmget_id=shmget(key,2048,IPC_CREAT|0644);
  perror("shmget()");
  
  printf("shmget_id \t:%d\n",shmget_id);
  
  //void *shmat(int shmid, const void *shmaddr, int shmflg);
  ptr=(char*)shmat(shmget_id,NULL,SHM_RND);
  
  strcpy(ptr,str);
  
  //int shmctl(int shmid, int cmd, struct shmid_ds *buf);
  shmctl(shmget_id,IPC_STAT,&buf);
  
  printf("shm_atime \t:%ld\n",buf.shm_atime);
  
  buf.shm_perm=usershm_perm;//important assigning 
  
  printf("shm_perm(uid) \t:%d\n",buf.shm_perm.uid);
  
    
  //int shmdt(const void *shmaddr);
  shmdt(ptr);
  

}
 

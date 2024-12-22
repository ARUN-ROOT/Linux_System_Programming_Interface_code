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

arun@arun:~/practise$ ./a.out
shmget(): No such file or directory
shmget_id 	:54
shm_segsz 	:2048
shm_atime 	:1676096533
shm_dtime 	:1676096436
shm_ctime 	:1676096436
shm_cpid 	:1676096533
shm_lpid 	:1676096533
shm_nattch 	:1
shm_key 	:-1
shm_uid 	:1000
shm_gid 	:1000
shm_cuid 	:1000
shm_cgid	:1000
shm_mode 	:420
shm_seq 	:0


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
  
  struct shmid_ds buffer;
  
  
  
  //key_t ftok(const char *pathname, int proj_id);
  key=ftok("shm_keyfile",55);
  
  //int shmget(key_t key, size_t size, int shmflg);
  shmget_id=shmget(key,2048,IPC_CREAT|0644);
  perror("shmget()");
  
  printf("shmget_id \t:%d\n",shmget_id);
  
  //void *shmat(int shmid, const void *shmaddr, int shmflg);
  ptr=(char*)shmat(shmget_id,NULL,SHM_RND);
  
  strcpy(ptr,str);
  
  /*struct shmid_ds {
               struct ipc_perm shm_perm;     
               size_t          shm_segsz;    
               time_t          shm_atime;    
               time_t          shm_dtime;    
               time_t          shm_ctime;    
               pid_t           shm_cpid;     
               pid_t           shm_lpid;    
               shmatt_t        shm_nattch;   
               ...
           };
           
            struct ipc_perm {
               key_t          __key;     
               uid_t          uid;       
               gid_t          gid;       
               uid_t          cuid;      
               gid_t          cgid;     
               unsigned short mode;     
                                          
               unsigned short __seq;     
           };
*/

  //int shmctl(int shmid, int cmd, struct shmid_ds *buf);
  shmctl(shmget_id,IPC_STAT,&buffer);
  
  printf("shm_segsz \t:%ld\n",buffer.shm_segsz);
  printf("shm_atime \t:%ld\n",buffer.shm_atime);
  printf("shm_dtime \t:%ld\n",buffer.shm_dtime);
  printf("shm_ctime \t:%ld\n",buffer.shm_ctime);
  printf("shm_cpid \t:%ld\n",buffer.shm_atime);
  printf("shm_lpid \t:%ld\n",buffer.shm_atime);
  printf("shm_nattch \t:%ld\n",buffer.shm_nattch);
  
  printf("shm_key \t:%d\n",buffer.shm_perm.__key);
  printf("shm_uid \t:%d\n",buffer.shm_perm.uid);
  printf("shm_gid \t:%d\n",buffer.shm_perm.gid);
  printf("shm_cuid \t:%d\n",buffer.shm_perm.cuid);
  printf("shm_cgid\t:%d\n",buffer.shm_perm.cgid);
  printf("shm_mode \t:%u\n",buffer.shm_perm.mode);
  printf("shm_seq \t:%u\n",buffer.shm_perm.__seq);


  
    
  //int shmdt(const void *shmaddr);
  shmdt(ptr);
  

}
 

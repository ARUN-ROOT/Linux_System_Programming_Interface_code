/************************************************************************************************************/
/* Name			: sender.c		                                      */	   
/* Date			: 21/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			:  starting and Ending address	find difference	*/
/*			                                                                                     */
/* o/p				: 

*/
                                                                                        
/************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define str "school of linux\nDharmapuri"

int main(int argc,char **argv)
{
  struct flock lock;
  int fd,i;
  
  lock.l_type=F_WRLCK;
  lock.l_whence=SEEK_SET;
  lock.l_start=0;
  lock.l_len=0;
  lock.l_pid=getpid();
  
  fd=open(argv[1],O_CREAT|O_RDWR,0666);
  if(fd==-1)
  {
    perror("open()");
    exit(-1);
  }
  
  //int fcntl(int fd, int cmd, ... /* arg */ );
  if(fcntl(fd,F_SETLK,&lock)<0)
  {
    perror("fcntl()");
    exit(-1);
  }
  
  if(write(fd,str,strlen(str))<0)
  {
    perror("write()");
    exit(-1);
  }
  
  fprintf(stderr,"prcess %d has written a data \n",lock.l_pid);
  
  for(i=0;i<10;i++)
  {
    printf("PID : %d writing data to the file \n",getpid() );
    sleep(1);
  }
  
  lock.l_type=F_UNLCK;
  //int fcntl(int fd, int cmd, ... /* arg */ );
  if(fcntl(fd,F_SETLK,&lock)<0)
  {
  perror("fcntl()");
  exit(-1);
  }
  close(fd);    
}
 


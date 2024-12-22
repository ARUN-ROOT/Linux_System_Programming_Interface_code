/************************************************************************************************************/
/* Name			: IPCreceiver.c		                                      */	   
/* Date			: 21/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
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


int main(int argc,char **argv)
{
  struct flock lock;
  int fd;
  char ch;
  
  lock.l_type=F_WRLCK;
  lock.l_whence=SEEK_SET;
  lock.l_start=0;
  lock.l_len=0;
  lock.l_pid=getpid();
  
  fd=open(argv[1],O_RDONLY);
  if(fd==-1)
  {
    perror("open()");
    exit(-1);
  }
  
  //int fcntl(int fd, int cmd, ... /* arg */ );
  if(fcntl(fd,F_GETLK,&lock)<0)
  {
    perror("fcntl()");
    exit(-1);
  }

  if(lock.l_type != F_UNLCK)
    printf("file is write lock");
    
  lock.l_type=F_RDLCK;
  if(fcntl(fd,F_SETLK,&lock)<0)
  {
    perror("fcntl() F_STLCK");
    exit(-1);
  }
  
  while(read(fd,&ch,1)>0)
    write(STDOUT_FILENO,&ch,1);
    
   /*Release the lock*/
  
  lock.l_type=F_UNLCK;
  if(fcntl(fd,F_SETLK,&lock)<0)
  {
    perror("fcntl()F_UNLCK");
    exit(-1);
  }  
  
  close(fd);  
}
 


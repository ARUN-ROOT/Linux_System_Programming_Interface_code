/************************************************************************************************************/
/* Name			: 7.NamedPIPEwrite	                                      */	   
/* Date			: 4/2/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			                                                                                     */
/* o/p				: 
 arun@arun:~/practise$ gcc practise.c -o write
arun@arun:~/practise$ ./write namedPipe

*/
                                                                                        
/************************************************************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#define SIZE 512

int main(int argc,char *argv[])
{
  int fd,n;
  char *str="Hi Arun Welcome to Named Pipe";
  
  mkfifo(argv[1],0664);
  fd=open(argv[1],O_WRONLY);
  
  if(fd==-1)
  {
    printf("error opening pipe %s\n",argv[1]);
    exit(-1);
  }
  
  write(fd,str,strlen(str));
  close(fd);
}

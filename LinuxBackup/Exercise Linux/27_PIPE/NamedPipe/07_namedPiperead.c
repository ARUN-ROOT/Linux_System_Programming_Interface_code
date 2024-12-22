/************************************************************************************************************/
/* Name			: 7.NamedPIPERead	                                      */	   
/* Date			: 4/2/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			                                                                                     */
/* o/p				: 
 
arun@arun:~/practise$ gcc progress.c -o read
arun@arun:~/practise$ ./read namedPipe
Hi Arun Welcome to Named Pipearun@arun:~/practise$ ./read namedPipe
Hi Arun Welcome to Named Pipearun@arun:~/practise$ ./read namedPipe



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
  char arr[SIZE];
  

  fd=open(argv[1],O_RDONLY);
  
  if(fd==-1)
  {
    printf("error opening pipe %s\n",argv[1]);
    exit(-1);
  }
  
  while((n=read(fd,arr,512))>0)
  {
    write(1,arr,n);
  }
  close(fd);
}

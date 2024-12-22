/************************************************************************************************************/
/* Name			: IPCreader		                                      */	   
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

#define SIZE 1024

int main(int argc,char **argv)
{
 int fd;
 ssize_t numread;
 char arr[SIZE];
 fd=open(argv[1],O_CREAT);
 
 if(fd==-1)
  {
    printf("error : opening a file \n");
    exit(-1);
  }
  else
  {
  printf("success with fd : %d\n",fd);
  }
  
  numread=read(fd,arr,SIZE);
  write(1,arr,numread);
  
  close(fd);  
}
 


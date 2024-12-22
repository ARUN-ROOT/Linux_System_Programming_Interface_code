/************************************************************************************************************/
/* Name			: 3.PIPE	                                      */	   
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
#include <unistd.h>
#include <string.h>


int main(int argc,char *argv[])
{
  int pipefd[2],rtn_pipe;
  ssize_t numread;
  char *pipecontent= "schooloflinux\n";
  
  char *str=malloc(sizeof(char)*20);
  
  //int pipe(int pipefd[2]);
  rtn_pipe= pipe(pipefd);
  
  if(rtn_pipe == -1)
  {
    perror("error in pipe()\n");
    exit(-1);
  }
  else
  {
    printf("success create pipe\n");
  }
  
  write(pipefd[1],pipecontent,strlen(pipecontent));//WRITING 1 END OF PIPE
  
  
  numread=read(pipefd[0],str,14);//READING ANOTHER END OF PIPE and STORE IN str ARRAY
  
  write(1,str,numread);
  
  free(str);
}
 


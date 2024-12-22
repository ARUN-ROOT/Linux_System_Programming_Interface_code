/************************************************************************************************************/
/* Name			: PIPE		                                      */	   
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


int main(int argc,char *argv[])
{
  int pipefd[2],rtn_pipe;
 
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
  write(pipefd[1],"schooloflinux\n",13);//WRITING 1 END OF PIPE
  read(pipefd[0],str,17);//READING ANOTHER END OF PIPE and STORE IN str ARRAY
  write(1,str,17);
  
  free(str);
}
 


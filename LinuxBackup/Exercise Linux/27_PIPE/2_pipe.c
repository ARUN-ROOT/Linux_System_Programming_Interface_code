/************************************************************************************************************/
/* Name			: 2.PIPE	                                      */	   
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
  write(pipefd[1],"schooloflinux\n",14);//WRITING 1 END OF PIPE
  write(pipefd[1],"Dharmapuri\n",10);
  
  read(pipefd[0],str,14);//READING ANOTHER END OF PIPE and STORE IN str ARRAY
  write(1,str,14);
  
  read(pipefd[0],str,10);//READING ANOTHER END OF PIPE and STORE IN str ARRAY 
  write(1,str,10);
  
  free(str);
}
 
 //Note: str Overwritted here school of linux not available
//*str=schooloflinux
//*str=Dharmapuri

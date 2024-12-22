/************************************************************************************************************/
/* Name			: 4.PIPE	                                      */	   
/* Date			: 21/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			                                                                                     */
/* o/p				: 

arun@arun:~/practise$ ./a.out
PID 	:3666
success create pipe

****************
pipefd[0] 	 : 3
pipefd[1] 	 : 4

****************
schooloflinux

arun@arun:~$ cat /proc/
cat: /proc/: Is a directory
arun@arun:~$ cd /proc/3666/fd
arun@arun:/proc/3666/fd$ ls
0  1  2  3  4   
Note : 3 and 4 shows red color



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
  
  printf("PID \t:%d\n",getpid());
  
  
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
  
  printf("\n****************\n");
  printf("pipefd[0] \t : %d\n",pipefd[0]);
  printf("pipefd[1] \t : %d\n",pipefd[1]);
  printf("\n****************\n");
  
  write(1,str,numread);
  
  getchar();
  
  free(str);
}
 


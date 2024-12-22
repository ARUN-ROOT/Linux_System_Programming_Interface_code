/************************************************************************************************************/
/* Name			: 5.PIPE	                                      */	   
/* Date			: 21/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			                                                                                     */
/* o/p				: 
 
arun@arun:~/practise$ ./a.out
Success in Create Pipe
Parent Process Created
Parent PID	:4221
Parent PPID	:2002
child process created
child PID 	 : 4222
child PPID	 : 4221
schooloflinux


*/
                                                                                        
/************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>


int main(int argc,char *argv[])
{
  int pipefd[2],rtn_pipe;
  pid_t pid;
  char *str=malloc(sizeof(char)*20);
  //int pipe(int pipefd[2]);
  rtn_pipe=pipe(pipefd);
  
  if(rtn_pipe==-1)
  {
    perror("error in pipe()\n");
    exit(-1);
  }
  else
  {
    printf("Success in Create Pipe\n");
  }
  
  pid=fork();
  
  if(pid==-1)
  {
    perror("error:fork()");
    exit(-1);
  }
  else if(pid==0)
  {
    printf("child process created\n");
    printf("child PID \t : %d\n",getpid());
    printf("child PPID\t : %d\n",getppid());
    read(pipefd[0],str,17);
    write(1,str,17);
  }
  else
  {
    printf("Parent Process Created\n");
    printf("Parent PID\t:%d\n",getpid());
    printf("Parent PPID\t:%d\n",getppid());
    write(pipefd[1],"schooloflinux\n",17);
  }
  getchar();
  
  free(str);
}
 


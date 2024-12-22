/************************************************************************************************************/
/* Name			: Taskfor child and parent                                                   */
/* Date			: 6/1/2023                                                                   */
/* Author			: Arun.V                                                                     */
/* Code link			:                                                                            */
/* Descrition			: create a fork and Call function child process calling adding function,     */
/*			          parent process calling Multiplication function                             */
/* o/p				:                                                                            */
/************************************************************************************************************/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int a=50,b=10,result;//declare global its showing entire program

int child_process();
int parent_process();

int main()
{ 
  pid_t pid;
  
  
    
  pid = fork();
  if(pid==-1)
  {
    perror("error:fork()");
    exit(-1);
  }
  else if(pid==0)
  {
     result=child_process();
  }
  else
  {
     result= parent_process();
  }
  printf("Result value : %d \n",result);
  printf("PPID : %d\n",getppid());
  printf("PID  : %d\n",getpid());
  
}

int child_process()
{
  return(a+b);
}

int parent_process()
{
  return(a*b);
}

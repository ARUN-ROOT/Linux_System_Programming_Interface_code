/* 
Name			: 
Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: 
o/p			:




 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{ 
  pid_t pid;
  
  int a=50,b=10,result;
    
  pid = fork();
  if(pid==-1)
  {
    perror("error:fork()");
    exit(-1);
  }
  else if(pid==0)
  {
    printf("child process \n");
    result=a*b;
    sleep(4);
  }
  else
  {
    printf("parent process \n");
    wait(NULL);  //Parent waiting
    result=a+b;
  }
  printf("Result value : %d \n",result);
  printf("PPID : %d\n",getppid());
  printf("PID  : %d\n",getpid());
  
}

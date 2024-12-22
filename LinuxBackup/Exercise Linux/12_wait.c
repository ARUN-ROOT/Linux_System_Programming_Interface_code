/* 
Name			: sleep and wait
Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: Parent run first and wait for child to complete their process and then Parent complete
o/p			:
arun@arun:~/practise$ gcc practise.c
arun@arun:~/practise$ ./a.out
parent process 
child process 
var value : 11 
PPID : 7502
PID  : 7503
var value : 100 
PPID : 1966
PID  : 7502




 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{ 
  pid_t pid;
  
  int var=10;
    
  pid = fork();
  if(pid==-1)
  {
    perror("error:fork()");
    exit(-1);
  }
  else if(pid==0)
  {
    printf("child process \n");
    var++;
    sleep(4);
  }
  else
  {
    printf("parent process \n");
    wait(NULL);  //Parent waiting
    var =100;
  }
  printf("var value : %d \n",var);
  printf("PPID : %d\n",getppid());
  printf("PID  : %d\n",getpid());
  
}

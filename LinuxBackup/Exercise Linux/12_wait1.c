/* 
Name			: sleep and wait
Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: Parent run first and wait for child to complete their process and then Parent complete
			  wait(): on success, returns the process ID of the terminated child; on error, -1 is returned.
o/p			:

arun@arun:~/practise$ ./a.out
parent process 
child process 
var value : 11 
PPID : 3053
PID  : 3054
wait return PID of Terminated child : 32767 
var value : 100 
PPID : 1974
PID  : 3053
wait return PID of Terminated child : 3054 

 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{ 
  pid_t pid;
  
  //pid_t wait(int *wstatus);
  pid_t w_rtn;
  
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
    w_rtn=wait(NULL);  //Parent waiting wait(): on success, returns the process ID of the terminated child; on error, -1 is returned.
    var =100;
  }
  printf("var value : %d \n",var);
  printf("PPID : %d\n",getppid());
  printf("PID  : %d\n",getpid());
  printf("wait return PID of Terminated child : %d \n",w_rtn);
  
}

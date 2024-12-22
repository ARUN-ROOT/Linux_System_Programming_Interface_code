/************************************************************************************************************/
/* Name			:                                              */
/* Date			: 7/1/2023                                                                   */
/* Author			: Arun.V                                                                     */
/* Code link			:                                                                            */
/* Descrition			:   parent wait until child complete  , change sleep value for observe*/
/*			                                      */
/* o/p				:   
arun@arun:~/practise$ ./a.out
Parent process PID : 8743 
child process PID : 8744
After Wait 
                                                                         */
/************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{ 
  pid_t pid;
  
  pid=fork();
  
  if(pid==0)
  {
    printf("child process PID : %d\n",getpid());
    sleep(2);
  }  
  else if(pid>0)
  {
    printf("Parent process PID : %d \n",getpid());
    wait(NULL);
    printf("After Wait \n");
  }
}



/* 
Name			:int execl(const char *pathname, const char *arg, ...(char  *) NULL);

Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: 
o/p			:





 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  char *pathname= "/bin/ls";
  char *arg1= "-ls";
  char *arg2= "/home/arun";

  
  pid_t pid;
  
  pid=fork();
  
  switch(pid)
  {
  	case 0:
  		printf("child process PID : %d \n",getpid());
  		printf("child process PPID : %d \n",getppid());
  		
  		
  	break;
  	case -1:
  		perror("failed to create child process");
  	break;
  	default:
  		printf("Parent process PID : %d \n",getpid());
  		printf("Parent process PPID : %d \n",getppid());
  		//int execl(const char *pathname, const char *arg, ...(char  *) NULL);
  		execl(pathname,arg1,arg2,NULL);
    	break;
  
  }

}

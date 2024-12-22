/* 
Name			://int execvp(const char *file, char *const argv[]);
Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: 
o/p			:
run@arun:~/practise$ ./a.out
Parent process PID : 3037 
Parent process PPID : 1966 
child process PID : 3038 
child process PPID : 3037 
then Firefox open

 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
 
  
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
  		//int execvp(const char *file, char *const argv[]);
    		execvp("firefox",NULL);//relative path
    	break;
  
  }

}

/* 
Name			: int execle(const char *pathname, const char *arg, .., (char *) NULL, char *const envp[] );

Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: 
o/p			:
arun@arun:~/practise$ ./a.out
Parent process PID : 5316 
Parent process PPID : 1966 
child process PID : 5317 
child process PPID : 5316 
Visit www.google.com:8080 from your browser.


 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  char *binarypath= "/bin/bash";
  char *arg1= "-c";
  char *arg2= "echo \"Visit $HOSTNAME:$PORT from your browser.\"";
  char *const env[]={"HOSTNAME=www.google.com","PORT=8080",NULL};

  
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
  		//int execle(const char *pathname, const char *arg, .., (char *) NULL, char *const envp[] );
  		execle(binarypath,binarypath,arg1,arg2,NULL,env);
    	break;
  
  }

}

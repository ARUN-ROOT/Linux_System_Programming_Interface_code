/* 
Name			:int execv(const char *pathname, char *const argv[]);
Date			: 31/12/2022
Author			: Arun.V
Code link		:
Descrition		: execv vector(argument in vector);
			 argument vector used so intilised argument vector char *argv[]= { };
                        Absolute Path given
                        Here Child process ls ,argv[]
                        Parent process open firefox application so given firefox path. which firefox in Terminal /usr/bin/firefox 
 o/p			:


 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  char *argv[]={"/bin/ls","-l","-r","-t",NULL};
  pid_t pid;
  
  pid=fork();
  
  switch(pid)
  {
  	case 0:
  		printf("child process PID : %d \n",getpid());
  		printf("child process PPID : %d \n",getppid());
  		//int execv(const char *pathname, char *const argv[]);
  		execv("/bin/ls",argv);//Absolute Path given
  	break;
  	case -1:
  		perror("failed to create child process");
  	break;
  	default:
  		printf("Parent process PID : %d \n",getpid());
  		printf("Parent process PPID : %d \n",getppid());
  		//int execv(const char *pathname, char *const argv[]);
    		execv("/usr/bin/firefox",NULL);//absolute path given
    	break;
  
  }

}

/* 
Name			:int execv(const char *pathname, char *const argv[]);
Date			: 31/12/2022
Author			: Arun.V
Code link		:
Descrition		: execv vector(argument in vector);
			 argument vector used from command line 
                        Absolute Path given
                        Here Child process ls ,argv[]
                        Parent process open firefox application so given firefox path. which firefox in Terminal /usr/bin/firefox 
 o/p			:
arun@arun:~/practise$ ./a.out /bin/ls -l -r -t
Parent process PID : 4756 
Parent process PPID : 2788 
child process PID : 4757 
child process PPID : 4756 
-rwxr-xr-x 1 root root 142144 Sep  5  2019 /bin/ls


 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
 // char *argv[]={"/bin/ls","-l","-r","-t",NULL};
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
    		execv("/usr/bin/firefox",NULL);
    	break;
  
  }

}

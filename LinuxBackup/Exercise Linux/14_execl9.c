/* 
Name			:int execl(const char *pathname, const char *arg, ...(char  *) NULL);

Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: 
o/p			:

arun@arun:~/practise$ ./a.out
Parent process PID : 4407 
Parent process PPID : 1966 
child process PID : 4408 
child process PPID : 4407 
total 4688
  20 -rwxrwxr-x 1 arun arun      16744 Dec  7 14:13  a.out
   4 -rw-rw-r-- 1 arun arun       3277 Dec 23 16:41  A.txt
  20 -rwxrwxr-x 1 arun arun      16744 Dec  7 14:30  cmd
2852 -rw-rw-r-- 1 arun arun    2916609 Dec 28 17:31  cscope.out
   4 drwxr-xr-x 3 arun arun       4096 Dec 25 11:03  Desktop
   4 drwxr-xr-x 2 arun arun       4096 Nov 29 11:59  Documents
   4 drwxr-xr-x 4 arun arun       4096 Dec 31 12:14  Downloads
  12 -rw-r--r-- 1 arun arun       8980 Nov 28 23:30  examples.desktop
   4 drwxrwxr-x 5 arun arun       4096 Jan  4 09:57 'Exercise Linux'




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
  		execl(pathname,pathname,arg1,arg2,NULL);//Two times pathname
    	break;
  
  }

}

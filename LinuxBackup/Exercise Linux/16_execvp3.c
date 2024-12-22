/* 
Name			://int execvp(const char *file, char *const argv[]);
Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: 
o/p			:
arun@arun:~/practise$ ./a.out
Parent process PID : 3178 
Parent process PPID : 1966 
child process PID : 3179 
child process PPID : 3178 
total 108
-rw-rw-r-- 1 arun arun   454 Dec 15 15:49 00_StandardMacros3.c
-rw-rw-r-- 1 arun arun  1168 Dec 15 14:15 08_lseekbasic.c
-rw-rw-r-- 1 arun arun   341 Dec 20 14:15 09_time1.c
-rw-rw-r-- 1 arun arun   866 Jan  4 09:45 16_execvp2.c
-rwxrwxr-x 1 arun arun 16976 Jan  4 09:54 a.out
-rw-rw-r-- 1 arun arun  3421 Dec 15 17:40 A.txt
-rw-rw-r-- 1 arun arun  1094 Dec 15 16:28 check.c
-rwx------ 1 arun arun     0 Dec 18 10:35 fileB.txt
-rwx------ 1 arun arun   299 Dec 21 18:20 log.txt
drwxrwxr-x 3 arun arun  4096 Dec 30 12:57 makefilecode
-rwxrwxr-x 1 arun arun 19480 Dec 28 11:06 practise
-rwxrwxr-x 1 arun arun 17136 Dec 16 17:41 practise~




 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
 char *argv[]={"ls","-l","/home/arun/practise",NULL};
  
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
    		execvp("ls",argv);//relative path
    	break;
  
  }

}

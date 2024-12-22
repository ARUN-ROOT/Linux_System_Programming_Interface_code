/* 
Name			://int execvp(const char *file, char *const argv[]);
Date			: 3/1/2023
Author			: Arun.V
Code link		:
Descrition		: 
o/p			:
arun@arun:~/practise$ ./a.out
Parent process PID : 6733 
Parent process PPID : 2788 
child process PID : 6734 
child process PPID : 6733 
total 104
-rw-rw-r-- 1 arun arun  1168 Dec 15 14:15 08_lseekbasic.c
-rw-rw-r-- 1 arun arun   454 Dec 15 15:49 00_StandardMacros3.c
-rw-rw-r-- 1 arun arun  1094 Dec 15 16:28 check.c
-rw-rw-r-- 1 arun arun  3421 Dec 15 17:40 A.txt
-rwxrwxr-x 1 arun arun 17136 Dec 16 17:41 practise~
-rwx------ 1 arun arun     0 Dec 18 10:35 fileB.txt
-rw-rw-r-- 1 arun arun   341 Dec 20 14:15 09_time1.c
-rwx------ 1 arun arun   299 Dec 21 18:20 log.txt
-rw-rw-r-- 1 arun arun    16 Dec 25 11:25 Welcome.txt
-rw-rw-r-- 1 arun arun    95 Dec 25 11:58 temp.txt
-rwxrwxr-x 1 arun arun 19480 Dec 28 11:06 practise
drwxrwxr-x 3 arun arun  4096 Dec 30 12:57 makefilecode
then Firefox open

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
  		execv("/bin/ls",argv);//Absolute path with Vector
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

/* 
Name			:
Date			: 30/12/2022
Author			: Arun.V
Code link		:
Descrition		: parent current getpid printed.Next inside child process we use execl function to remove copy of current process
			 (i.e.copy of Parent process)New process is implemeted.current listing  -ls 
 o/p			:arun@arun:~/practise$ ./a.out
parent process 8228 
arun@arun:~/practise$ total 108
-rw-rw-r-- 1 arun arun   454 Dec 15 15:49 00_StandardMacros3.c
-rw-rw-r-- 1 arun arun  1168 Dec 15 14:15 08_lseekbasic.c
-rw-rw-r-- 1 arun arun   341 Dec 20 14:15 09_time1.c
-rwxrwxr-x 1 arun arun 16832 Dec 30 13:56 a.out
-rw-rw-r-- 1 arun arun  3421 Dec 15 17:40 A.txt
-rw-rw-r-- 1 arun arun  1094 Dec 15 16:28 check.c
-rwx------ 1 arun arun     0 Dec 18 10:35 fileB.txt
-rwx------ 1 arun arun   299 Dec 21 18:20 log.txt
drwxrwxr-x 3 arun arun  4096 Dec 30 12:57 makefilecode
-rwxrwxr-x 1 arun arun 19480 Dec 28 11:06 practise
-rwxrwxr-x 1 arun arun 17136 Dec 16 17:41 practise~

 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
 pid_t pid;
 
 pid=fork();
 
 if(pid==0)
 {  
   // int execl(const char *pathname, const char *arg, .. (char  *) NULL );

   execl("/bin/ls","my_ls","-l",NULL);
 }
 else if(pid>0)
 {
   printf("parent process %d \n",getpid());
 }
}

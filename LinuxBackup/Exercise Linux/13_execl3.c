/* 
Name			:
Date			: 30/12/2022
Author			: Arun.V
Code link		:
Descrition		: 
 o/p			:
 arun@arun:~/practise$ ./a.out
parent process 8353 
arun@arun:~/practise$ total 108
2393465 -rw-rw-r-- 1 arun arun    16 Dec 25 11:25 Welcome.txt
2392509 -rw-rw-r-- 1 arun arun    95 Dec 25 11:58 temp.txt
2364909 -rw-rw-r-- 1 arun arun  4330 Dec 17 23:36 progress.c
2388668 -rw-rw-r-- 1 arun arun   560 Dec 30 14:08 practise.c
2360383 -rwxrwxr-x 1 arun arun 17136 Dec 16 17:41 practise~
2368736 -rwxrwxr-x 1 arun arun 19480 Dec 28 11:06 practise
2367016 drwxrwxr-x 3 arun arun  4096 Dec 30 12:57 makefilecode
2371772 -rwx------ 1 arun arun   299 Dec 21 18:20 log.txt
2365916 -rwx------ 1 arun arun     0 Dec 18 10:35 fileB.txt
2380843 -rw-rw-r-- 1 arun arun  1094 Dec 15 16:28 check.c
2364338 -rw-rw-r-- 1 arun arun  3421 Dec 15 17:40 A.txt


 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
 pid_t pid;
 
 pid=fork();
 
 if(pid==0)
 {  //  int execl(const char *pathname, const char *arg, ...
     //           /* (char  *) NULL */);

   execl("/bin/ls","my_ls","-l","-r","-i",NULL);//ls -lri
   printf("Hello world two\n");//not executed current process changed by execl (simply below execl down all erased)
 }
 else if(pid>0)
 {
   printf("parent process %d \n",getpid());
 }
}

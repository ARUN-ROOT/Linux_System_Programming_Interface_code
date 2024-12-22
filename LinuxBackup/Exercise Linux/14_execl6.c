/* 
Name			:
Date			: 31/12/2022
Author			: Arun.V
Code link		:
Descrition		: one line is added above execl printf("Hello world one")  This line is not printed actually it should print
                         whatever before execl reason is we need complete line by next line\n printf("Hello world one\n") it will store 				  stdio buffer.
                         Try 1st printf("Hello world one");check output if it is Print  or not
                         Try 2nd printf("Hello world one\n")check output if it is print or not
                         
 o/p			:arun@arun:~/practise$ ./a.out
parent process 2826 
Hello world oneHello world two
arun@arun:~/practise$ total 116
2393465 -rw-rw-r-- 1 arun arun    16 Dec 25 11:25 Welcome.txt
2392509 -rw-rw-r-- 1 arun arun    95 Dec 25 11:58 temp.txt
2364909 -rw-rw-r-- 1 arun arun  4330 Dec 17 23:36 progress.c



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
   printf("Hello world one");
   printf("Hello world two\n");
   execl("/bin/ls","my_ls","-l","-r","-i",NULL);//ls -lri
   printf("Hello world final\n");//not executed current process changed by execl (simply below execl down all erased)
 }
 else if(pid>0)
 {
   printf("parent process %d \n",getpid());
 }
}


/*
case 1 :printf("Hello world one");

case 2:printf("Hello world one\n");

case 3:printf("Hello world one");
	printf("Hello world two\n");
	
case 4:printf("Hello world one");
	printf("Hello world two\n");
	printf("Hello world three");

case 5:printf("Hello world one");
	printf("Hello world two\n");
	printf("Hello world three");
	printf("Hello world four\n");

*/




/* 
Name			:
Date			: 30/12/2022
Author			: Arun.V
Code link		:
Descrition		: This code givn current process id for both Child and Parent
			output first executed parent then Child
 o/p			:arun@arun:~/practise$ ./a.out
			parent process 8128 
			child process 8129 
			arun@arun:~/practise$ 

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
   printf("child process %d \n",getpid());
 }
 else if(pid>0)
 {
   printf("parent process %d \n",getpid());
 }
}

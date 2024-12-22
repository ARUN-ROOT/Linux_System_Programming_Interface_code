/* 
Name			: Signal:SIGFPE
Date			: 5/1/2023
Author			: Arun.V
Code link		:
Descrition		:Run one Terminal,open another Terminal kill -10 PID send it.
o/p			:
arun@arun:~/practise$ ./a.out
PID : 5694
Hai
arun@arun:~/practise$ kill -10 5694 //kill SIGUSR1 PID


 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>


void action()
{
   write(1,"Hai",4);
}
int main(int argc,char *argv[])
{
 pid_t pid;
 printf("PID : %d\n",getpid());
 //void ( *signal(int signum, void (*handler)(int)) ) (int);
 signal(SIGUSR1,action);
 
  getchar();
}


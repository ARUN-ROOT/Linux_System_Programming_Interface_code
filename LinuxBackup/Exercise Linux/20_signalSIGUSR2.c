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
arun@arun:~/practise$ kill -12 5694 //kill SIGUSR2 PID


 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>


void action()
{
   write(1,"Hai\n",5);
}
int main(int argc,char *argv[])
{
 pid_t pid;
 int i=0;
 //void ( *signal(int signum, void (*handler)(int)) ) (int);
 signal(SIGUSR2,action);
 
  while(1)
  {
    printf("%d PID : %d\n",i,getpid());
    i++;
    sleep(1);
  }
}


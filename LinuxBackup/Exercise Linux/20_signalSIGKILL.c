/* 
Name			: Signal:SIGKILL
Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: Run 1 Terminal ,another Terminal kill -9 3180
			so kill the process
o/p			:
arun@arun:~/practise$ ./a.out
0 3180
1 3180
2 3180
3 3180
4 3180
5 3180
6 3180
Killed

arun@arun:~/practise$ kill -9 3180


 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void ctrl_c()
{
  write(1,"i got received signal : SIGINT\n",30);
}

void f_kill()
{
  write(1,"i got received signal : SIGKILL\n",30);
}
int main()
{ 
  int x=0;
  
  signal(SIGINT,ctrl_c);
  signal(SIGKILL,f_kill);
  while(1)
  {
    printf("%d %d\n",x,getpid());
    x++;
    sleep(1);
  }
}


/* 
Name			: Signal:SIGINT
Date			: 4/1/2023
Author			: Arun.V
Code link		:
Descrition		: 
o/p			:
arun@arun:~/practise$ ./a.out
0 3142
1 3142
2 3142
^Ci got received signal : SIGINT3 3142
4 3142
5 3142
6 3142
7 3142


 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void ctrl_c()
{
  write(1,"i got received signal : SIGINT\n",30);
}

int main()
{ 
  int x=0;
  signal(SIGINT,ctrl_c);
  while(1)
  {
    printf("%d %d\n",x,getpid());
    x++;
    sleep(1);
  }
}


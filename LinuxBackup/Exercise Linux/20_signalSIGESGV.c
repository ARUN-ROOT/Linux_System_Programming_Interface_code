/* 
Name			: Signal:SIGSEGV
Date			: 5/1/2023
Author			: Arun.V
Code link		:
Descrition		: Segmentation fault occur,SIGSEGV trigger control flows to function.
			printf the message and Exit
o/p			:
arun@arun:~/practise$ ./a.out
0x55f2e7ab301a
writing on read only

 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

void segflt()
{
  write(1,"writing on read only\n",25);
  sleep(1);
  exit(-1);
}
int main()
{

  char *s ="ARUN";
  printf("%p\n",s);
  signal(SIGSEGV,segflt); 
  *(s+3)='u';
 
/*
 int *p=(int *)0x10;
 signal(SIGSEGV,segflt); 
 printf("%d\n",*p);
 *p=25;
  printf("%d\n",*p);
 */
 
}


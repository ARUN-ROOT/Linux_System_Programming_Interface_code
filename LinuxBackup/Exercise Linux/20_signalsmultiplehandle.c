/************************************************************************************************************/
/* Name			: signal() multiple signal with same function handle                                              */
/* Date			: 7/1/2023                                                                   */
/* Author			: Arun.V                                                                     */
/* Code link			:                                                                            */
/* Descrition			:     */
/*			                                      */
/* o/p				:   
                                                                         */
/************************************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

void handle(int sig)
{ 
  if(sig==SIGFPE)
  {
  printf("floating point occur sig number is  : %d \n",sig); //sig num 8 display
  write(1,"change b value greater than Zero\n",40);
  sleep(2);
  }
  if(sig==SIGKILL)
  {
  printf("process is killed  %d\n",sig);
  write(1,"process is killed\n",18);
  }
}


int main(int argc,char *argv[])
{ 
  
  int a,b,result;
  a=atoi(argv[1]);
  b=atoi(argv[2]);
  
  //void ( *signal(int sig , void (* handler )(int)) ) (int);
  signal(SIGFPE,handle);
  signal(SIGKILL,handle);
  
  printf("PID %d\n",getpid());
  printf("%d\n",result=a/b);
 
  
}



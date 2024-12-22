/************************************************************************************************************/
/* Name			: signal() SIGFPE                                                */
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

void infinity(int sig)
{ 
  printf("floating point occur sig number is  : %d \n",sig); //sig num 8 display
  write(1,"change b value greater than Zero\n",40);
  exit(-1);
}


int main(int argc,char *argv[])
{
  int a,b,result;
  a=atoi(argv[1]);
  b=atoi(argv[2]);
  //void ( *signal(int sig , void (* handler )(int)) ) (int);
  signal(SIGFPE,infinity);
  
  printf("%d\n",result=a/b);
 
  
}



/************************************************************************************************************/
/* Name			: signal();                                                */
/* Date			: 7/1/2023                                                                   */
/* Author			: Arun.V                                                                     */
/* Code link			:                                                                            */
/* Descrition			:     */
/*			                                      */
/* o/p				:   
arun@arun:~/practise$ ./a.out
0 PID : 8838 
1 PID : 8838 
^CCatch !! sig is : 2 
2 PID : 8838 
3 PID : 8838 
^CCatch !! sig is : 2 
4 PID : 8838 
^CCatch !! sig is : 2 

^Z
[16]+  Stopped                                                                           */
/************************************************************************************************************/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>


int main()
{ 
  int x=0;

  void handle(int sig)
  {
    printf("Catch !! sig is : %d \n",sig);//sig num dispaly 2
  }
  
  signal(SIGINT,handle);
  
  while(1)
  {
    printf("%d PID : %d \n",x,getpid());
    x++;
    sleep(1);
  
  }
  
}






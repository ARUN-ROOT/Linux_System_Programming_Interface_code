/************************************************************************************************************/
/* Name			:   Zombie state    - child is terminated but  parent is busy some other                    
                                   task                                    */
/* Date			: 11/1/2023                                                                   */
/* Author			: Arun.V                                                                     */
/* Code link			:                                                                            */
/* Descrition			:   
                                   */
/*			                                      */
/* o/p				:   

                                                                      */
/************************************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>



int main(int argc,char *argv[])
{ 
    pid_t pid;
    
    pid=fork();
    
    if(pid==0)
    {
      printf("chid proc PID : %d \n",getpid());
      printf("child proc PPID : %d \n",getppid());
     
    }
    else if(pid>0)
    {
      printf("Parent proc PID : %d \n",getpid());
      printf("Parent proc PPID : %d \n",getppid());
      printf("before sleep\n");
      sleep(10);
      printf("After sleep \n");
      printf("Parent proc PID : %d \n",getpid());
      printf("Parent proc PPID : %d \n",getppid());
    }
  getchar();
}



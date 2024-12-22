/************************************************************************************************************/
/* Name			:   Orphan state    - child is running even parent is dies                                    */
/* Date			: 11/1/2023                                                                   */
/* Author			: Arun.V                                                                     */
/* Code link			:                                                                            */
/* Descrition			:   child proc PPID is changed     before and after sleep because parent is 
				 terminated while child is on Sleep,after child wake up parent not there.
				 After sleep child PPID coming from Epoch/mudar/upstart/systemd based in OS
				 
                                   */
/*			                                      */
/* o/p				:   
arun@arun:~/practise$ gcc practise.c
arun@arun:~/practise$ ./a.out
Parent proc PID : 8238 
Parent proc PPID : 2713 
chid proc PID : 8239 
child proc PPID : 8238 
before sleep
arun@arun:~/practise$ After sleep 
chid proc PID : 8239 
child proc PPID : 1420 
   ps -aux
   1000    1420       1 Ss   /lib/systemd/systemd --user
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
      printf("before sleep\n");
      sleep(10);
      printf("After sleep \n");
      printf("chid proc PID : %d \n",getpid());
      printf("child proc PPID : %d \n",getppid());
      
    }
    else if(pid>0)
    {
      printf("Parent proc PID : %d \n",getpid());
      printf("Parent proc PPID : %d \n",getppid());
    }
  
}



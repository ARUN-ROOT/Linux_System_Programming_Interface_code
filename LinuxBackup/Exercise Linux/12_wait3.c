/************************************************************************************************************/
/* Name			:                                              */
/* Date			: 7/1/2023                                                                   */
/* Author			: Arun.V                                                                     */
/* Code link			:                                                                            */
/* Descrition			:   parent wait until child complete  , change sleep value for observe       
                                   so many Wait status implemented*/
/*			                                      */
/* o/p				:   
arun@arun:~/practise$ ./a.out
Parent process PID : 9327 
child process PID : 9328
After Wait 
wait_rtn 9328
status 25600
WIFEXITED(status) 1
WEXITSTATUS(status) 100 
                                                                         */
/************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{ 
  pid_t pid,status,wait_rtn;
  
  pid=fork();
  
  if(pid==0)
  {
    printf("child process PID : %d\n",getpid());
    sleep(4);//important
    exit(100); //important
  }  
  else if(pid>0)
  {
    printf("Parent process PID : %d \n",getpid());
    //pid_t wait(int *wstatus);
    wait_rtn=wait(&status);//child process PID return in Parent
    printf("After Wait \n");
    printf("wait_rtn %d\n",wait_rtn);
    printf("status %d\n",status);//check Macros
    printf("WIFEXITED(status) %d\n",WIFEXITED(status));
    printf("WEXITSTATUS(status) %d \n",WEXITSTATUS(status));//In child Process wait 100 come here
  }
}



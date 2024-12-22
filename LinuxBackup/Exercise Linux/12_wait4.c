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
Parent process PID : 9691 
child process PID : 9692
After Wait 
wait_rtn 9692
status 2
WIFEXITED(status) 0
WEXITSTATUS(status) 0 
WIFSIGNALED(status) 1 
WTERMSIG(status) 2 
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
    sleep(10);//important
    exit(100); //important
  }  
  else if(pid>0)
  {
    printf("Parent process PID : %d \n",getpid());
    //pid_t waitpid(pid_t pid, int *wstatus, int options);
    wait_rtn=waitpid(-1,&status,0);//
    printf("After Wait \n");
    printf("wait_rtn %d\n",wait_rtn);
    printf("status %d\n",status);//check Macros
    printf("WIFEXITED(status) %d\n",WIFEXITED(status));
    printf("WEXITSTATUS(status) %d \n",WEXITSTATUS(status));//In child Process wait 100 come here
    printf("WIFSIGNALED(status) %d \n",WIFSIGNALED(status));// open another terminal kill -9 pid of chils
    printf("WTERMSIG(status) %d \n",WTERMSIG(status));//kill -2 pid of child
  }
}



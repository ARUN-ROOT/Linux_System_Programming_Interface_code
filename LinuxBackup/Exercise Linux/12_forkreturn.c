/* 
Name	: Fork return
Date	: 24/12/2022
Descrition : we create fork child and calling process executed.
             Note carefully, here condition first execute parent process of that fork after child process 
 o/p	:
This process PID 6892
(pid>0)
parent process PID: 6893
parent process getpid: 6892
(pid==0)
child process PID: 0
child process getpid : 6893


                                      P (6892) getpid
                                         |___|
                                         (fork)
                 P pid 6893 getpid 6892            C1 pid 0  getpid 6893
                 |___|                           |___|
            1st Exected                        2nd Executd
                
 */


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{  
   pid_t pid;
   //pid_t fork(void);
   printf("\tThis process PID %d\n",getpid());//getpid means current running process PID
   pid=fork();
   if(pid==0)//2nd execute
   { printf("child process PID: %d\n",pid);
     printf("child process getpid : %d\n",getpid());
     
   }
   else if(pid>0)  //first execute and 
   {
     printf("parent process PID: %d\n",pid);
     printf("parent process getpid: %d\n",getpid());
     
   }
   else if(pid==-1)
   {
     perror("fork()");
   }

}


/* 
Name	: Fork return
Date	: 24/12/2022
Descrition : we create fork child and calling process executed.
             Note carefully, here condition first execute parent process of that fork after child process 
 o/p	:
arun@arun:~/practise$ gcc practise.c -o practise
arun@arun:~/practise$ ./practise
parent process PID: 6779
parent process PID: 6780
child process PID: 6780
child process PID: 0
                   P
                  (fork)
                 P            C1
            1st Exected    2nd Executd
                
 */


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{  
   pid_t pid;
   //pid_t fork(void);
   pid=fork();
   if(pid==0)//2nd execute
   {
     printf("child process PID: %d\n",getpid());
     printf("child process PID: %d\n",pid);
   }
   else if(pid>0)  //first execute and 
   {
     printf("parent process PID: %d\n",getpid());
     printf("parent process PID: %d\n",pid);
   }
   else if(pid==-1)
   {
     perror("fork()");
   }

}


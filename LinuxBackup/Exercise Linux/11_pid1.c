/* 
Name	: PID and PPID (Identification)
Date	: 22/12/2022
Descrition : getpid() returns the process ID (PID) of the calling process.  (This is often used by routines that generate unique temporary file names.)

       getppid() returns the process ID of the parent of the calling process.  This will be either the ID of the process that created this
       process  using  fork(), or, if that process has already terminated, the ID of the process to which this process has been reparented
       (either init(1) or a "subreaper" process defined via the prctl(2) PR_SET_CHILD_SUBREAPER operation).


 o/p	:
 arun@arun:~/practise$ ./practise
process id : 6804
parent process id : 5891 (Terminal bash)

ps -e -o uid,pid,ppid,cmd

 */


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{  
   pid_t pid,ppid;
   
   //pid_t getpid(void);
   //pid_t getppid(void);
   pid=getpid();
   ppid=getppid();
   
   printf("process id : %d\n",pid);
   printf("parent process id : %d\n",ppid);
   sleep(1);

}



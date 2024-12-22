/************************************************************************************************************/
/* Name			: sigaction();                                                               */
/* Date			: 7/1/2023                                                                   */
/* Author			: Arun.V                                                                     */
/* Code link			:                                                                            */
/* Descrition			:  sigaction Newact is used.Check restart and without.                       */
/*			           whatever sigaction structute is updated.                                  */
/* o/p				:  
arun@arun:~/practise$ ./a.out               									*/
/* 0 PID : 6688 												*/
/* 1 PID : 6688 												*/	
/* ^Chai newact												*/
/* %d2 PID : 6688                                                                                           */
/* ^Chai newact
/* %d3 PID : 6688 
/* 4 PID : 6688 

                                                                          */
/************************************************************************************************************/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>


int main()
{ 
  int x=0;
  struct sigaction newsa;
  
 /*int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
 
   struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };

  */

  void newctrl_c()
  {
     write(1,"hai newact\n",14);
  }
  
  newsa.sa_handler= newctrl_c;
  newsa.sa_flags =SA_RESTART; //check with and without
  
  sigaction(SIGINT,&newsa,NULL);//newact
  
  while(1)
  {
    printf("%d PID : %d \n",x,getpid());
    x++;
    sleep(1);
  
  }
  
}




/*
https://www.ibm.com/docs/en/i/7.2?topic=ssw_ibm_i_72/apis/sigactn.html
sig
    (Input) A signal from the list defined in Control Signals Table.

*act
    (Input) A pointer to the sigaction structure that describes the action to be taken for the signal. Can be NULL.

    If act is a NULL pointer, signal handling is unchanged. sigaction() can be used to inquire about the current handling of signal sig.

    If act is not NULL, the action specified in the sigaction structure becomes the new action associated with sig.
*oact
    (Output) A pointer to a storage location where sigaction() can store a sigaction structure. This structure contains the action currently associated with sig. Can be NULL.

    If oact is a NULL pointer, sigaction() does not store this information.

*/


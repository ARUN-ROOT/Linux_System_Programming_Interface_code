/* 
Name	: clock monotonic
Date	: 22/12/2022
Descrition : sec and nanosec
 o/p	:
arun@arun:~/practise$ ./practise
4994 : seconds 
313309851 : nano seconds 
4995 : seconds 
549528247 : nanosec 
1 : seconds 
236218396 : nano seconds 

 */


#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>
    
int main()
{   
   struct timespec st;
   struct timespec en;
   
   //int clock_gettime(clockid_t clk_id, struct timespec *tp); //man 3 clock_gettime
   clock_gettime(CLOCK_MONOTONIC,&st);
   for(int i=0;i<100000000;i++);
   sleep(1);//check with and without
   clock_gettime(CLOCK_MONOTONIC,&en);
   
   printf("%ld : seconds \n",st.tv_sec);
   printf("%ld : nano seconds \n",st.tv_nsec);
   
   printf("%ld : seconds \n",en.tv_sec);
   printf("%ld : nanosec \n",en.tv_nsec);
   
   printf("%ld : seconds \n",en.tv_sec - st.tv_sec);
   printf("%ld : nano seconds \n",en.tv_nsec - st.tv_nsec);
   
}


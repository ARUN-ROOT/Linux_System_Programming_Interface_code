/* 
Name	: 
Date	: 22/12/2022
Descrition : user and system
 o/p	:
 arun@arun:~/practise$ ./practise
user : 0 
sys  : 0 
user : 24 
sys  : 0 
arun@arun:~/practise$ 
 */


#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>
    
int main()
{   
   struct tms st;
   struct tms en;
   //clock_t times(struct tms *buf);
   times(&st);
   for(int i=0;i<100000000;i++);
   sleep(1);
   times(&en);
   
   printf("user : %ld \n",st.tms_utime);
   printf("sys  : %ld \n",st.tms_stime);
   
   printf("user : %ld \n",en.tms_utime);
   printf("sys  : %ld \n",en.tms_stime);

}


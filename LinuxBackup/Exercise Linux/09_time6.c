/* 
Name	: 
Date	: 22/12/2022
Descrition : how much clock taken to complete the loop
	    ending sec-starting sec
 o/p	:
arun@arun:~/practise$ gcc practise.c -o practise
arun@arun:~/practise$ ./practise
235411 clock used 
arun@arun:~/practise
 */


#include <stdio.h>
#include <time.h>
#include <unistd.h>
    
int main()
{   
   clock_t st,en;
  //clock_t clock(void);
  
  st= clock();
  for(int i=0;i<100000000;i++);
  en= clock();
  printf("%ld clock used \n",(en-st));
  
}


/* 
Name	: 
Date	: 22/12/2022
Descrition : how much seconds taken to complete the loop
	    ending sec-starting sec
 o/p	:
 arun@arun:~/practise$ ./practise
2 seconds used 
arun@arun:~/practise$ 

 */


#include <stdio.h>
#include <time.h>
#include <unistd.h>
    
int main()
{   
   
  time_t st,en;
  //time_t time(time_t *tloc); it return epoch
  st=time(NULL);
  for(int i=0;i<100000000;i++); //semicolon must
  sleep(1);
  en=time(NULL);
  printf("%ld seconds used \n",(en-st));
  
}


/* 
Name	: 
Date	: 19/12/2022
Descrition : time() returns the time as the number of seconds since the Epoch,
O/P	: arun@arun:~/practise$ gcc practise.c -o practise
	arun@arun:~/practise$ ./practise
	1671525879arun@arun:~/practise$ 



 */


#include <stdio.h>
#include <time.h>


int main(int argc, char *argv[])
{  
  time_t t;
  //time_t time(time_t *tloc);time() returns the time as the number of seconds since the Epoch, man 2 time
  t=time(NULL);
  printf("%ld",t);
    
}





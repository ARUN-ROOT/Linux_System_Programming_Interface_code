/* 
Name	: 
Date	: 22/12/2022
Descrition : CLOCKS_PER_SEC used
 o/p	:
arun@arun:~/practise$ ./practise
0.235986 : sec used 
235986 :clock used 
arun@arun:~/practise$ 
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
  double sec=(double) (en-st)/CLOCKS_PER_SEC ;
  printf("%lf : sec used \n",sec);
  printf("%ld :clock used \n",(en-st));
  
}


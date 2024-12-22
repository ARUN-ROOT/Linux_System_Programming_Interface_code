/* 
Name	: 
Date	: 19/12/2022
Descrition : 
O/P	:arun@arun:~/practise$ ./practise
Date : Tue Dec 20 14:43:41 2022




 */


#include <stdio.h>
#include <time.h>


int main(int argc, char *argv[])
{  
  time_t tm;
  struct tm *my_tm;
  char *t_str;
  
  //time_t time(time_t *tloc);
  tm=time(NULL);
  
  //char *ctime(const time_t *timep);
  t_str=ctime(&tm);//ctime(t) is equivalent to asctime
  printf("Date : %s ",t_str);
}





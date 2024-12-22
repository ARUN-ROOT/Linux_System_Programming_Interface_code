/* 
Name	: 
Date	: 19/12/2022
Descrition : 
O/P	:arun@arun:~/practise$ ./practise
Date : Tue Dec 20 14:38:25 2022
9



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
  //struct tm *localtime(const time_t *timep);
  my_tm = localtime(&tm);
  //char *asctime(const struct tm *tm);
  t_str = asctime(my_tm);
  printf("Date : %s ",t_str);
}





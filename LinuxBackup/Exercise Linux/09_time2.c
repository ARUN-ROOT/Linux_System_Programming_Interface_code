/* 
Name	: 
Date	: 19/12/2022
Descrition : 
O/P	:
arun@arun:~/Exercise Linux$ ./a.out
Date 22 12 2022
arun@arun:~/Exercise Linux$ 

 */


#include <stdio.h>
#include <time.h>


int main(int argc, char *argv[])
{  
  time_t tm;
  struct tm *my_tm;
  
  //time_t time(time_t *tloc);time() returns the time as the number of seconds since the Epoch, man 2 time
  tm=time(NULL);
  
  //struct tm *localtime(const time_t *timep);//man 3 ctime 
  my_tm = localtime(&tm); 
  
  printf("Date %d",my_tm->tm_mday);
  printf(" %d",(my_tm->tm_mon + 1));
  printf(" %d\n",(my_tm -> tm_year +1900)); 
}

//The ctime(), gmtime() and localtime() functions all take an argument of data type time_t, which represents calendar time.



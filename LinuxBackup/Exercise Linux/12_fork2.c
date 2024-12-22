/* 
Name	: 
Date	: 24/12/2022
Descrition : 
 o/p	:
arun@arun:~/practise$ ./practise
hello world
hello world
hello world
hello world
arun@arun:~/practise$ hello world
hello world
hello world
hello world


 */


#include <stdio.h>
#include <unistd.h>


int main()
{  
   fork();
   fork();
   fork();
   printf("hello world\n");      

}


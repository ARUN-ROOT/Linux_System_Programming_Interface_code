/************************************************************************************************************/
/* Name			:  main.c                         */	   
/* Date			: 26/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: Header definitions	*/
/*			          */
/* o/p				: 

arun@arun:~/Exercise Linux/29_static_Library/Task4$ gcc -c header.c 
arun@arun:~/Exercise Linux/29_static_Library/Task4$ gcc -c main.c
main.c: In function ‘main’:
main.c:22:7: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
   22 |   num=atoi(argv[1]);
      |       ^~~~
arun@arun:~/Exercise Linux/29_static_Library/Task4$ gcc -c main.c
arun@arun:~/Exercise Linux/29_static_Library/Task4$ gcc main.o header.o -o info
arun@arun:~/Exercise Linux/29_static_Library/Task4$ ./info 25
your age 25 


*/
                                                                                        
/************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main(int argc,char* argv[])
{ 
  int num;
  num=atoi(argv[1]);
  age(num);
}

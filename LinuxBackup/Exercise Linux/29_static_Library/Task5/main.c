/************************************************************************************************************/
/* Name			:  main.c                         */	   
/* Date			: 26/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: Header definitions	*/
/*			          */
/* o/p				: 

arun@arun:~/Exercise Linux/29_static_Library/Task5$ gcc -c header.c
arun@arun:~/Exercise Linux/29_static_Library/Task5$ ar -rcs test.a header.o
arun@arun:~/Exercise Linux/29_static_Library/Task5$ gcc -o info main.c test.a 
arun@arun:~/Exercise Linux/29_static_Library/Task5$ ./info arun 25
your age 25 
your name arun 
arun@arun:~/Exercise Linux/29_static_Library/Task5$ 


*/
                                                                                        
/************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main(int argc,char* argv[])
{ 
  int num;
  num=atoi(argv[2]);
  age(num);
  name(argv[1]);
}

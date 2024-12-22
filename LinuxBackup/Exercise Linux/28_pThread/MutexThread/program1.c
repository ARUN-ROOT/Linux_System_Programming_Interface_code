/************************************************************************************************************/
/* Name			:  program1.c                            */	   
/* Date			: 26/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			          */
/* o/p				: 
arun@arun:~/practise$ time ./a.out 
MAX 	:1000000
gvar 	:2000000

real	0m0.011s
user	0m0.011s
sys	0m0.000s



*/
                                                                                        
/************************************************************************************************************/

#include <stdio.h>

#define MAX 1000000

typedef unsigned int uint_t;

uint_t gvar=0;

void fun()
{
  for(int i=0;i<MAX;i++)
  {
    gvar++;
  }
}

int main(int argc,char *argv[])
{
  fun();
  fun();
  printf("MAX \t:%d\n",MAX);
  printf("gvar \t:%d\n",gvar);
  
}
 

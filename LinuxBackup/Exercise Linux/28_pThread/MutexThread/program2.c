/************************************************************************************************************/
/* Name			:  program2.c                            */	   
/* Date			: 26/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			:without pthread_join 	*/
/*			          */
/* o/p				: 


arun@arun:~/practise$ gcc practise.c -lpthread
arun@arun:~/practise$ time ./a.out 
MAX 	:1000000
gvar 	:1015246

real	0m0.019s
user	0m0.035s
sys	0m0.000s
*/
                                                                                        
/************************************************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 1000000

typedef unsigned int uint_t;

uint_t gvar=0;

void *fun()
{
  for(int i=0;i<MAX;i++)
  {
    gvar++;
  }
}

int main(int argc,char *argv[])
{
  pthread_t my_newthread;
  pthread_create(&my_newthread,NULL,fun,NULL);
  fun();
  printf("MAX \t:%d\n",MAX);
  printf("gvar \t:%d\n",gvar);
  
}
 

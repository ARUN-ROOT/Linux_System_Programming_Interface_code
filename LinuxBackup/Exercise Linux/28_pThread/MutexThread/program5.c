/************************************************************************************************************/
/* Name			:  program5.c                            */	   
/* Date			: 26/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: Avoid 	*/
/*			          */
/* o/p				: 

arun@arun:~/practise$ time ./a.out 


test 	 1000000
gvar 0x557cec11f024 
test 0x7f0967e3fee0

test 	 1000000
gvar 0x557cec11f024 
test 0x7ffd0c7469a0

MAX 	:1000000
gvar 	:0

real	0m0.010s
user	0m0.016s
sys	0m0.001s


*/
                                                                                        
/************************************************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 1000000

typedef unsigned int uint_t;

uint_t gvar=0;
pthread_mutex_t lock;

void *fun()
{
  uint_t test=0;
  for(uint_t i=0;i<MAX;i++)
  {
    //pthread_mutex_lock(&lock);
    test=test+1;
   // pthread_mutex_unlock(&lock);
  }
  printf("\ntest \t %d\n",test);
  printf("gvar %p \n",&gvar);
  printf("test %p\n",&test);
}

int main(int argc,char *argv[])
{
  pthread_t my_newthread;
  pthread_create(&my_newthread,NULL,fun,NULL);
  printf("\n");
  fun();
  pthread_join(my_newthread,NULL);
  printf("\nMAX \t:%d\n",MAX);
  printf("gvar \t:%d\n",gvar);
  
}
 

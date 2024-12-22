/************************************************************************************************************/
/* Name			:  program4.c                            */	   
/* Date			: 26/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: mutexlock used it gives correct output .But it takes more user time 	*/
/*			          */
/* o/p				: 

arun@arun:~/practise$ time ./a.out 
MAX 	:1000000
gvar 	:2000000

real	0m0.203s
user	0m0.272s
sys	0m0.130s


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
  for(int i=0;i<MAX;i++)
  {
    pthread_mutex_lock(&lock);
    gvar++;
    pthread_mutex_unlock(&lock);
  }
}

int main(int argc,char *argv[])
{
  pthread_t my_newthread;
  pthread_create(&my_newthread,NULL,fun,NULL);
  fun();
  pthread_join(my_newthread,NULL);
  printf("MAX \t:%d\n",MAX);
  printf("gvar \t:%d\n",gvar);
  
}
 

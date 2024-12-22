/************************************************************************************************************/
/* Name			: Pthread_create and Join .c                              */	   
/* Date			: 19/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			          */
/* o/p				: 

arun@arun:~/practise$ gcc practise.c -lpthread
arun@arun:~/practise$ ./a.out
fun2() 0
fun1() 0
fun1() 1
fun2() 1
fun1() 2
fun2() 2
fun1() 3
fun1() 4

*/
                                                                                        
/************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *fun1()
{
  for(int i=0;i<5;i++)
  {
    printf("fun1() %d\n",i);
    sleep(1);
  }
}

void fun2()
{
  for(int i=0;i<3;i++)
  {
    printf("fun2() %d\n",i);
    sleep(1);
  }
}


int main(int argc,char *argv[])
{
  pthread_t newthread;
  //int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
  pthread_create(&newthread,NULL,&fun1,NULL);
  fun2();
  //int pthread_join(pthread_t thread, void **retval);
  pthread_join(newthread,NULL);//RUN WITHOUT OR WITH THIS LINE
  return 0;
}
 

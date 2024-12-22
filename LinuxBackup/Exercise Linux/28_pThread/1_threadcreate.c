/************************************************************************************************************/
/* Name			: Pthread_create.c                              */	   
/* Date			: 19/2/2023                                                                 */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: 	*/
/*			          */
/* o/p				: 
arun@arun:~/practise$ gcc practise.c -lpthread
arun@arun:~/practise$ ./a.out
fun2()
fun1()
fun2()
fun1()
fun2()

*/
                                                                                        
/************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *fun1()
{
  for(;;)
  {
    printf("fun1()\n");
    sleep(1);
  }
}

void fun2()
{
  for(;;)
  {
    printf("fun2()\n");
    sleep(1);
  }
}


int main(int argc,char *argv[])
{
  pthread_t newthread;
  //int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
  pthread_create(&newthread,NULL,&fun1,NULL);
  fun2();
  return 0;
}
 

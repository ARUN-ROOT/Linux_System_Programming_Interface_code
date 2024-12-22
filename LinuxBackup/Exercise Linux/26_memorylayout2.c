/************************************************************************************************************/
/* Name			: MemoryLayout 		                                      */	   
/* Date			:19/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			:  starting and Ending address	find difference	*/
/*			                                                                                     */
/* o/p				: 
arun@arun:~/practise$ ./a.out
SC_PAGESIZE 4096 
PID	:2337

statting add 0x563678738ac0
Ending address 0x563678738ac0


*/
                                                                                        
/************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define ONE_GB (1<<62)

int main(int argc,char **argv)
{
  printf("SC_PAGESIZE %ld \n",sysconf(_SC_PAGESIZE));
  printf("PID\t:%d\n",getpid());
  getchar();
  void *ptr=malloc(ONE_GB);
  printf("statting add %p\n",ptr);
  void *ptr1=(void*)(ptr+(1<<62));
  printf("Ending address %p\n",ptr1);
  getchar();
  
  
}
 


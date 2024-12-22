/************************************************************************************************************/
/* Name			: MemoryLayout sbrk()			                                      */	   
/* Date			:12/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			:   */ 
/* Descrition			:  here you are getting Program break address after Heap ending      	*/
/*				  so.. check with cat /proc/PID/maps Monitor Heap ending Address		*/
/*			                                                                                     */
/* o/p				: 
arun@arun:~/practise$ ./a.out
PID	:2325
program break 	: 0x5614dddc8000


*/
                                                                                        
/************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>



int main(int argc,char **argv)
{
  printf("PID\t:%d\n",getpid());
  void *ptr=sbrk(0);
  printf("program break \t: %p\n",ptr);
  getchar();
  
}
 


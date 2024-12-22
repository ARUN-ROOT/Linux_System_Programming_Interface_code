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
SC_PAGESIZE 4096 
PID	:3677
program break 	: 0x5635cd51a000

size of char 	:1
program break after increment 	: 0x5635cd51a001
program break address 0x5635cd51a001


5635cd4f9000-5635cd51a000 rw-p 00000000 00:00 0                          [heap]

5635cd4f9000-5635cd51b000 rw-p 00000000 00:00 0                          [heap]

*/
                                                                                        
/************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>



int main(int argc,char **argv)
{
  printf("SC_PAGESIZE %ld \n",sysconf(_SC_PAGESIZE));
  printf("PID\t:%d\n",getpid());
  void *ptr=sbrk(0);
  printf("program break \t: %p\n",ptr);
  getchar();
  printf("size of char \t:%ld\n",sizeof(char));
  ptr=(void*)((char*)ptr+1);
  printf("program break after increment \t: %p\n",ptr);
  brk(ptr);
  void *ptr1=sbrk(0);
  printf("program break address %p\n",ptr1);
  getchar();
  
  
}
 


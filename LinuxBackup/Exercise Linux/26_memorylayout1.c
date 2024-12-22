/************************************************************************************************************/
/* Name			:   MemoryLayout                    */						
/* Date			: 12/1/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			:   */ 
/* Descrition			:  	*/

/*			                                                                                     */
/* o/p				: 



*/
                                                                                        
/************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

extern int edata,etext,end;
extern int environ;

int a=0;
int b;

int main(int argc,char **argv)
{
  int c=0;
  static int d;
  printf("PID \t\t :%d\n",getpid());
  int *ptr=(int*)malloc(16*sizeof(int));

  printf("etext \t :%p\n",&etext);//Text(code) segment end
  printf("a=0\t :%p\n",&a);//Global intilised data seg
  printf("edata \t:%p\n",&edata);
  printf("b\t:%p\n",&b);
  printf("end\t:%p\n",&end);
  printf("c=0 \t :%p\n",&c);//stack
  printf("d \t:%p\n",&d);//Data seg
  printf("Stck &ptr\t:%p\n",&ptr);//This one give stack address
  printf("Heap ptr\t:%p\n",ptr);//This one give Heap address //ptr+0
  printf("main \t:%p\n",&main);
  printf("argc\t:%p\n",&argc);
  printf("argv\t:%p\n",&argv);
  printf("argv\t\t:%p\n",argv);
  printf("environ\t:%p\n",&environ);
  getchar();
 }
 


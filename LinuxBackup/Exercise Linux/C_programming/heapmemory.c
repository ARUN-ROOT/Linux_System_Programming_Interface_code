/* 
Name			:
Date			: 31/12/2022
Author			: Arun.V
Code link		:
Descrition		: Malloc
                         
 o/p			:


 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{ 
   int a=5;
   int *ptr;
   
   printf("PID %d\n",getpid());
   
   ptr=(int*)malloc(a*sizeof(int)); 
   if(ptr==NULL)
   {
     printf("Memory Not allocated\n");
     exit(0);
   }
   else
   {
     printf("successfull\n");
   }
   
   for(int i=0;i<10;i++)
   printf("%p\n",ptr+i);
   
   
   //558b966fe000-558b9671f000 rw-p 00000000 00:00 0                          [heap]
   printf("Heap size %ld\n",0x558b9671f000-0x558b966fe000);
   getchar();
}



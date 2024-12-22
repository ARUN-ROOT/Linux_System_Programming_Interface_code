/* 
Name			: Function Pointer
Date			: 25/12/2022
Author			: Arun.V
Code link		:
Descrition		: Here function pointer used with no return value.
			  we need to assign address of another function to this function pointer
			  then using this function pointer passing argument.
			  Note: 
 o/p			: add function address 0x55da5c881149
			function pointer content 0x55da5c881149
			5
			15


 */

#include <stdio.h>

void add(int a,int b)
{
 printf("%d\n",a+b);
 
}

void (*ptr)(int ,int );

int main()
{  
  
  printf("add function address %p\n",&add);   
  
  ptr=&add;					//assign address of another function to this function pointer
  printf("function pointer content %p\n",ptr);
  
  ptr(2,3);//possible                   //using this function pointer passing argument 
  
 (*ptr)(5,10);//possible 		//using this function pointer passing argument 
 
 // *ptr(8,9);//Not possible
}






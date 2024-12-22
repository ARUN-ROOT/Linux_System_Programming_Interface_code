/* 
Name			: Function Pointer
Date			: 25/12/2022
Author			: Arun.V
Code link		:
Descrition		: Here function pointer used with return value.
			  we need to assign address of another function to this function pointer
			  then using this function pointer passing argument.
			  Note: 
 o/p			:add function address 0x55b04fa02149
			function pointer content 0x55b04fa02149
			5
			total :5 
			15
			tota1 : 15 
 */

#include <stdio.h>

int add(int a,int b)
{
 printf("%d\n",a+b);
 return (a+b);
}

int (*ptr)(int ,int );

int main()
{  
  int total,total1;                           //Two integer variable
  
  printf("add function address %p\n",&add);   
  
  ptr=&add;					//assign address of another function to this function pointer
  printf("function pointer content %p\n",ptr);
  
  total=ptr(2,3);//possible                   //using this function pointer passing argument return typre int so stored in integer 						variable .
  printf("total :%d \n",total);
  
  total1=(*ptr)(5,10);//possible 		//using this function pointer passing argument return typre int so stored in integer 						variable .
  printf("tota1 : %d \n",total1);
}






/* 
Name			:Array of  Function Pointer
Date			: 25/12/2022
Author			: Arun.V
Code link		:
Descrition		: 
 o/p			:
 */

#include <stdio.h>

int add(int a,int b)
{

 return (a+b);
}

int sub(int a,int b)
{
 return (a+b);
}
int (*ptr[2])(int ,int );

int main()
{  
  int add_result,sub_result;                           //Two integer variable
  
  printf("add function address %p\n",&add);  
  printf("sub function address %p\n\n",&sub);   
  
  ptr[0]=&add;					//assign address of another function to this function pointer
  ptr[1]=&sub;
  
  printf("0th index ptr[0] function pointer address %p\n",ptr[0]);
  printf("1st index ptr[1] function pointer address %p\n",ptr[1]);
  
  
  printf("0th index ptr[0] function pointer address %p\n",&ptr[0]);
  printf("1st index ptr[1] function pointer address %p\n",&ptr[1]);
  
  printf("but ptr %p \n",ptr);
    printf("but ptr+1 %p \n",ptr+1);
  
  add_result=ptr[0](2,3);//possible                  
  printf("add_result :%d \n",add_result);
  
  sub_result=ptr[1](10,5);//possible                  
  printf("sub_result :%d \n",sub_result);
  
}






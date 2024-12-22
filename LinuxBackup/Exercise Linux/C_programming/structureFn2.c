/* 
Name	: Structure and Function
Date	: 22/12/2022
Descrition : Passing structure member address as argument to function under Normal structure variable stu;
 o/p	:10


 */


#include <stdio.h>
void passing(int *i);
struct student
{
  int i;//Normal Datatype(whatever int ,char) //Not Pointer
};

    
int main()
{  
   struct student stu;//Normal Structure Variable stu.
   stu.i=10;
   passing(&(stu.i));//passing address of structure member with Normal Structure variable

}

void passing(int *i)//Call by Reference
{
  printf("%d\n",*i);
}

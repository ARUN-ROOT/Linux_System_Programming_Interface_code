/* 
Name	: Structure and Function
Date	: 22/12/2022
Descrition : Passing structure member value as argument to function under Normal structure variable stu;
 o/p	:10


 */


#include <stdio.h>
void passing(int i);
struct student
{
  int i;//Normal Datatype(whatever int ,char) //Not Pointer
};

    
int main()
{  
   struct student stu;//Normal Structure Variable stu.
   stu.i=10;
   passing(stu.i);//passing value of structure member with Normal structure Variable

}

void passing(int i)//call by value
{
  printf("%d\n",i);
}

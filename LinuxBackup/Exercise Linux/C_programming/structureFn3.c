/* 
Name	: Structure and Function
Date	: 22/12/2022
Descrition : Passing Normal structure variable as argument to function
 o/p	:10


 */


#include <stdio.h>

struct student
{
  int i;
};

void passing(struct student su);//prototype after structure only
    
int main()
{  
   struct student stu;//Normal Structure Variable stu.
   stu.i=10;
   passing(stu);//passing structure normal variable

}

void passing(struct student st)
{
  printf("%d\n",st.i);
}

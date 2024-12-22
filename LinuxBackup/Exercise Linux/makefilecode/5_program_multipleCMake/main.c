#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"

int main()
{
  int add_result,sub_result,mul_result;
  printf("main code\n");
  add_result=add(2,55);
  printf("add_result %d\n",add_result);
  sub_result=sub(100,50);
  printf("sub_result %d\n",sub_result);
  mul_result=mul(2,8);
  printf("mul_result %d\n",mul_result);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

  long int res;
  char *endptr;
  char *str ="123 arun";


  printf("argc : %d\n" ,argc);
  res=strtol(str,&endptr,10);
  printf("%ld\n",res);
  printf("%s\n",endptr);
  
}

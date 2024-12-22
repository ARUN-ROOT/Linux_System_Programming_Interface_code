#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{  int i;
    char *endpt;
    long int res;
  printf("argc : %d \n" ,argc);
  
  
  for(i=0;i<=argc;i++)
    printf("argv[%d]  : %s \n",i,argv[i]); 
    
    
  res=strtol(argv[1],&endpt,10);
  printf("res %lu\n",res);
  printf("end %s\n",endpt);

}

//	Remove file.


#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   int i;

   for(i=0; i<argc; i++)
   {
      if(remove(argv[i])>0) 
      {
	 printf("%s", argv[i]);
      }
   }
}

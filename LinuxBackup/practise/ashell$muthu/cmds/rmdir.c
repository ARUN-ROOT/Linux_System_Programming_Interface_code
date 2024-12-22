//delete a multiple new directory directory using command line.

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   int i;

   for(i=0; i<argc; i++)
   {
      if(rmdir(argv[i]) > 0)
      {
	 printf("%s", argv[i]);
      }
   }
}

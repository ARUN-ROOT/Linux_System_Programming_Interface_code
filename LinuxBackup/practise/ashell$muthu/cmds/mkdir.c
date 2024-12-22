//	create a multiple new dirextory using command kine.

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char ** argv)
{
   int i;

   for(i=0; i<argc; i++)
   {
      // Try creating the directory
      if ( mkdir(argv[i], 0755) > 0 )
      {
	 printf("%s", argv[i]);
      }
   }
}

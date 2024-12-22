//	concatenate files and print on the standard output.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
   int fd, i;
   char buf[1024];

   fd = open (argv[1], O_CREAT|O_RDONLY, 0777);
   if( fd == -1)
   {
      printf("File open errror\n");
   }

   while( ( i= read( fd, buf, 1)  ) > 0)
   {
      printf("%c", buf[0]);
   }

   close(fd);
}

//	Move (rename) file.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
   int fd,fd1,i;
   char buf[1024];

   fd = open(argv[1], O_RDONLY, 0777);
   if(fd == -1)
   {
      printf("file error open\n");
   }

   fd1 = creat ( argv[2], 0777 );
   if( fd1 == -1 )
   {
      printf("file creating error\n");
   }

   while( i = read( fd, buf, 1) > 0)
   {
      write( fd1, buf, 1);
   }

   remove(argv[1]);
   close(fd);
   close(fd1);
}

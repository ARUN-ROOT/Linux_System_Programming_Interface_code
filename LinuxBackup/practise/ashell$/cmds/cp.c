//      copy one file to another file

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
   int fd,fd2,fd3;
   ssize_t fd1;
   char buf;
   size_t count;

   fd = open ( argv[1], O_RDONLY, 0644 );
   if( fd == -1 )
   {
      printf("Erorr creating file opening\n");
   }
   
   fd2 = open ( argv[2], O_WRONLY | O_CREAT, 0644 );
   if( fd == -1 )
   {
      printf("Erorr creating file opening\n");
   }
   
   while( read ( fd, &buf, 1) )
   {
      write( fd2, &buf, 1 );
   }

   printf("copy sucessfuly\n");
   close (fd);
   close (fd2);
}


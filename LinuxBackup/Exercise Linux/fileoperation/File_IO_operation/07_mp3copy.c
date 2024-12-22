/*
Name		: File read and write  i.e copy one MP3 file to anotherMP3
Date		: 12/12/2022
Description	: 

o/p: 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFR1 5679690

int main(int argc, char *argv[])
{
  int fd1,fd2,fd3,fd4;
  char buf[BUFR1];
  
  fd1=open("./Kannanule.mp3",O_RDONLY);
  if(fd1== -1)
  {
    perror("open()");
    exit(-1);
  }
  printf("haii");
  
  fd2=read(fd1,buf,BUFR1);
   if(fd2== -1)
  {
    perror("read()");
    exit(-1);
  }
  ///////////
  fd3=open("./songcopy.mp3",O_CREAT | O_RDWR,S_IRUSR|S_IWUSR);
    if(fd3== -1)
  {
    perror("open()");
    exit(-1);
  }
  fd4=write(fd3,buf,BUFR1);
    if(fd4 == -1)
  {
    perror("write()");
    exit(-1);
  }
  
  close(fd1);
  close(fd2);
  close(fd3);
  close(fd4);
}




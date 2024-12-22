/* 
Name	: filewrite.c
Date	: 10/12/2022
Descrition : Getting file name from Command line arg argv[1],Create  a file  and Write it using pointer
             Here checking argument also.
             content also mention here in code itself
o/p: gcc 03_filewrite.c -o 03_filewrite
     gcc ./03_filewrite filename.txt   
     

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int fd,flags;
  mode_t filemode;
  char *buf = "Hai Arun Welcome in c txt";//content 
  ssize_t num_write;

  flags= O_CREAT | O_WRONLY;//important line
  filemode= S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH ;

  if(argc<2)
  {
     printf("%s : missing operand <exe filename>",argv[0]);
     exit(-1);
  }

  fd=open(argv[1],flags,filemode);//getting filename from Command line argument and Create
  if(fd==-1)
  {
	  perror("open()");
	  exit(-1);
  }
  printf("success");
  num_write = write(fd,buf,(strlen(buf)-1));
  if(num_write== -1)
  {
    perror("write()");
    exit(-1);
  } 
close(fd);
}


/*
Name		: File read
Date		: 10/12/2022
Description	: reading Existing file a file and opening and reading it.

o/p gcc 02_fileread -o 02_fileread
    ./02_fileread
    successfully open file with fd : 3
    Running Here(Read from given txt file)
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 512 //512 

int main(int argc, char *argv[])
{
  int open_flag,file_fd,i;
  mode_t file_mode;
  char buf[BUF_SIZE];//read store in buf
  ssize_t numread;
  
  open_flag = O_CREAT;
 
  file_fd=open("A.txt",open_flag);//given path name of Existing file
  if(file_fd==-1)
  {
    printf("error : opening a file \n");
    exit(-1);
  }
  else
  {
    printf("successfully open  with fd : %d \n",file_fd);
    numread = read(file_fd,buf,BUF_SIZE);
    for(i=0;i<numread;i++)
    {
     printf("%c",buf[i]);// print the character in terminal
    }
  }
  close(file_fd);
}




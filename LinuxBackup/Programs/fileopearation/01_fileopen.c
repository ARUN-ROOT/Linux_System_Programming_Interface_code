/*
Name		: File opening
Date		: 10/12/2022
Description	: creating a file and opening it.Checking 
                 directly given filename

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int open_flag,file_fd;
  mode_t file_mode;
  
  open_flag = O_CREAT;  //Create a new file
  file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH ;//rw-rw-r-- permission
  
  file_fd=open("fileopen.txt",open_flag,file_mode);//open syscalls for openning file ,directly given filename
  if(file_fd== -1)//check for error
  {
  printf("error : opening a file \n");
  exit(-1);//stdlib.h exit
  }
  else
  {
  printf("Sucessfully open with fd : %d \n",file_fd);
  }
  close(file_fd);

}

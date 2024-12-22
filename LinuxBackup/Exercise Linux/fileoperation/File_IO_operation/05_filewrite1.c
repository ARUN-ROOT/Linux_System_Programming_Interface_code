/* 
Name	: filewrite.c
Date	: 10/12/2022
Description :	checking argument count,
		Creating file1 , open and Writing content in bufer[0]
		Creating file2 , open and Writing content in bufer[1]
		Both file name getting from argument vector argv[]
		print both fd value
		close both files with fd. fd is 3 and 4 because same process running
o/p: gcc -
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

  int fd[1],flags;
  mode_t filemode;
  char *buf[] = {"Hai Arun Welcome","Gopi welcome"};//array of string pointer
  ssize_t num_write[1];

  flags= O_CREAT | O_WRONLY;
  filemode= S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH ;//rw-rw-r--
/***************checking argument count *********************/
  
  if(argc<3)//./a.out file1.txt file2.txt
  {
     printf("%s : missing operand <exe filename>",argv[0]);
     exit(-1);
  }
/***************Creating file1 , open and Writing content in bufer[0]*********************/
  
  fd[0]=open(argv[1],flags,filemode);//file name getting from argv[1]
  if(fd[0]==-1)
  {
	  perror("open()");
	  exit(-1);
  }
  printf("sucessful create and open %s with fd : %d \n",argv[1],fd[0]);
  num_write[0] = write(fd[0],buf[0],(strlen(buf[0])));//Do not use strlen(buf)-1 
  if(num_write[0]== -1)
  {

    perror("write()");
    exit(-1);
  } 
  /***************Creating file2 , open and Writing content in bufer[1]*********************/
   fd[1]=open(argv[2],flags,filemode);//file name getting from argv[2]
  if(fd[1]==-1)
  {
	  perror("open()");
	  exit(-1);
  }
  printf("sucessful create and open %s with fd :  %d \n",argv[2],fd[1]);
  num_write[1] = write(fd[1],buf[1],(strlen(buf[1])));//Do not use strlen(buf)-1 
  if(num_write[1]== -1)
  {

    perror("write()");
    exit(-1);
  } 
close(fd[0]);
close(fd[1]);
}



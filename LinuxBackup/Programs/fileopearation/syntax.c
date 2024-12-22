/*
Name		: 
Date		: 
Description	: 

o/p		: 

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//# define SIZE 512

int main(int argc, char *argv[])
{
  int fd,flag,i;
  mode_t 
  ssize_t numread,numwrite;
  //char arr[BUF_SIZE];
  
   flag = O_CREAT;
   
   filePerW= S_IRWXU | S_IRWXG | S_IRWXO ;
 
  fdR=open("A.txt",open_flagR);
  if(fdR==-1)
  {
    perror("open()");
    exit(-1);
  }
  else
  {
    printf("successfully open reading with fd : %d \n",fdR);
    numread = read(fdR,arr,BUF_SIZE);//Reading content in file store in buffer
    for(i=0;i<numread;i++)
    {
     printf("%c",arr[i]);
    }
  }
  
  /********** Open Another file and Write *********************************/
  fdW=open("TESTC.txt",open_flagW,filePerW);
  if(fdW==-1)
  {
   perror("open()");
   exit(-1);
  }
  numwrite =write(fdW,arr,strlen(arr)-2);
  if(numwrite== -1)
  {
  perror("write()");
  exit(-1);
  }
  
  close(fdR);
  close(fdW);
}




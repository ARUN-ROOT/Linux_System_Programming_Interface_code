/*
Name		: File read and write i.e copy one file to another
Date		: 10/12/2022
Description	: reading Existing file a file and store in buf and opening another file and Write it from buf content.

o/p: 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFR1 512

int main(int argc, char *argv[])
{
  int open_flagR,fdR,i;
  int open_flagW,fdW;
  mode_t filePer;
  mode_t filePerW;
  ssize_t numread,numwrite;
  char bufR[BUFR1];
  
   open_flagR = O_CREAT;
   open_flagW = O_CREAT | O_WRONLY;
   filePerW= S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH ;
 
  fdR=open("test.txt",open_flagR);
  if(fdR==-1)
  {
    perror("open()");
    exit(-1);
  }
  else
  {
    printf("successfully open reading with fd : %d \n",fdR);
    numread = read(fdR,bufR,BUFR1);//Reading content in file store in buffer
    for(i=0;i<numread;i++)
    {
     printf("%c",bufR[i]);
    }
  }
  
  /********** Open Another file and Write *********************************/
  fdW=open("TESTC.txt",open_flagW,filePerW);
  if(fdW==-1)
  {
   perror("open()");
   exit(-1);
  }
  numwrite =write(fdW,bufR,(strlen(bufR)-1));
  if(numwrite== -1)
  {
  perror("write()");
  exit(-1);
  }
  
  close(fdR);
  close(fdW);
}




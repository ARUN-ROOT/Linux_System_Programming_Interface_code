/* 
Name	: log creation
Date	: 20/12/2022
Descrition : 
 




 */


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LOG(msg) { \
    logFd=open("log.txt",O_CREAT|O_RDWR|O_APPEND,S_IRWXU);\
       write(logFd,msg,strlen(msg));\
     }

int main(int argc, char *argv[])
{    
  int fd,logFd,line=0;
 
  
  fd=open("A.txt",O_CREAT|O_RDWR,S_IRWXU);
  printf("Line number is: %d\n",line = __LINE__);

  LOG ("OPEN SUCCESS\n");
  LOG("LOG CREATED\n");

    
}


/*
Name		: 
Date		: 12/12/2022 
Description	: open a file in Particular path and write something
                 if you using O_APPEND not overwrite
                 *str = "Arun"; //string given in Array pointer
o/p: 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[])
{
 int fd1,fd2,flag,mode;
 
 char *str = "ARUN gOPIGHGFJGF";
 
 flag=O_CREAT | O_RDWR | O_APPEND;
 mode = S_IRWXU | S_IRWXG | S_IRWXO ;
 
 fd1=open("/home/arun/Programs/fileopearation/welcome.txt",flag,mode);
 if(fd1==-1)
 {
   perror("open()");
   exit(-1);
 }
 printf("success\n");
 
 fd2=write(fd1,str,strlen(str));
  if(fd2 ==-1)
 {
   perror("write()");
   exit(-1);
 }
 
 close(fd1);
 close(fd2);
}




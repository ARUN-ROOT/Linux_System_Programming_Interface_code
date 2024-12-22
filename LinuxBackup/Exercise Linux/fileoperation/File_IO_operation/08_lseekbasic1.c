/* 
Name	: 
Date	: 15/12/2022
Descrition : from line number it display the content from file
o/p	: arun@arun:~/practise$ gcc practise.c -o practise
arun@arun:~/practise$ ./practise A.txt 2
lseek(): Success
lseek(): Success

two
three
four
five


 */


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define SIZE 512

int main(int argc, char *argv[])
{    
  int openfd,i,l_no=0,fl_no=0;
  char arr[SIZE];
  ssize_t numread;
  off_t fp=0,l_fp=0;
  
  l_no=atoi(argv[2]);
  
  openfd=open(argv[1],O_RDONLY);
  if(openfd==-1)
  {
    perror("open()");
    exit(-1);
  }
  numread=read(openfd,arr,SIZE);
  if(numread==-1)
  {
    perror("read()");
    exit(-1);
  }
    
  fp=lseek(openfd,0,SEEK_SET);
  perror("lseek()");  
  for(i=0;i<numread;i++)
  {  l_fp++;                    //take another variable line file pointer++
     if(arr[i]=='\n')
     {
       fl_no++;
     }
     if(fl_no == (l_no-2) ) //check with and without -2
     {
       fp=l_fp;
     }    
     
  }  
    
  lseek(openfd,fp,SEEK_CUR);
  perror("lseek()");
     
  numread=read(openfd,arr,SIZE);
  write(1,arr,numread); 
  
  close(openfd);
  
}


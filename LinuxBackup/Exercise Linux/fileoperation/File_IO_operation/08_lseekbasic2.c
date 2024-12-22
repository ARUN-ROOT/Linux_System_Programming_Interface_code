/* 
Name	: 
Date	: 15/12/2022
Descrition : 


 */


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define SIZE 3421

int main(int argc, char *argv[])
{    
  int fd,userl_no=0,i,filel_no=0,temp=0;
  char arr[SIZE];
  ssize_t numread;
  off_t fp=0,m_fp=0;;
  
  userl_no= atoi(argv[1]);
  
  fd=open("A.txt",O_RDONLY);
  if(fd==-1)
  {
    perror("open()");
    exit(-1);
  }
  
  numread=read(fd,arr,SIZE);
  if(numread == -1)
  {
    perror("read()");
    exit(-1);
  }
  //*******line number*******////
  fp=lseek(fd,0,SEEK_SET);//cursor move to 0th place
  perror("lseek()");
  
  for( i= 0;i<numread;i++)
  {  
    m_fp++;//moving file pointer
    
   if(arr[i]== '\n')
   {
     filel_no++;
   }  
   if(filel_no==userl_no-1)
   {
     break;
   }
  }
  printf("%ld\n",m_fp); 
  fp=m_fp;
  lseek(fd,fp,SEEK_CUR);
  perror("perror()");
  numread=read(fd,arr,SIZE);
  write(1,arr,SIZE);
  close(fd);
    
}


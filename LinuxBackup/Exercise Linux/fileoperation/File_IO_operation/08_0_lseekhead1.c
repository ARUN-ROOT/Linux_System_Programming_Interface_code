/* 
Name	: 
Date	: 15/12/2022
Descrition : lseek head command

arun@arun:~/practise$ gcc practise.c -o practise
arun@arun:~/practise$ ./practise 3
lseek(): Success
lseek(): Success
     1	root:x:0:0:root:/root:/bin/bash
     2	daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
     3	bin:x:2:2:bin:/bin:/usr/sbin/nologin
arun@arun:~/practise$ 




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
  //******* finding line number*******////
  fp=lseek(fd,0,SEEK_SET);//cursor move to 0th place
  perror("lseek()");
  
  for( i= 0;i<numread;i++)
  {  
    m_fp++;//moving file pointer
    
   if(arr[i]== '\n')
   {
     filel_no++;
   }  
   if(filel_no==userl_no) //filel_no match userline number come out loop meanwhile m_fp also increase
   {
     break;
   }
  }
 
  printf("moving file pointer m_fp %ld\n",m_fp);//important m_fp hold last value 
  lseek(fd,0,SEEK_SET);// pointer move to 0th position
  perror("lseek()");
  numread=read(fd,arr,m_fp);//numread =read(fd,arr,SIZE)//Here if u use this all upto 53 lines 3421 bytes
  write(1,arr,numread);
  close(fd);
    
}


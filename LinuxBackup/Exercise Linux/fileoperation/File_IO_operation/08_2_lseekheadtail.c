/* 
Name	: 
Date	: 17/12/2022
Descrition : lseek headtail command
              user want to print inbetween lines like 5 to 10
O/P:

improvement : swap apply


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
  int fd,fd1,i,filel_no=0,first=0,last=0,cursor=0;
  char arr[SIZE],temp[SIZE],barr[SIZE];
  ssize_t numread,numwrite,numread1,numwrite1,numread2;
  off_t fp,m_fp=0,m_fp_eachline[SIZE]={0},count=1,ok,var1,var2;
  
  first=atoi(argv[1]);
  last=atoi(argv[2]);
  
  fd=open("A.txt",O_CREAT|O_RDWR,S_IRWXU);
  if(fd==-1)
  {
    perror("open()");
    exit(-1);
  }
  
  numread=read(fd,arr,SIZE);
  perror("read()");
  
  ///***** Finding Line Number*****///
  fp=lseek(fd,0,SEEK_SET);
  perror("lseek()");
  
  for(i=0;i<numread;i++)
  {
    m_fp++;
    if(arr[i]=='\n')
    { 
      m_fp_eachline[count]=m_fp;
      count++;
      filel_no++;
    }  
      
  }
  
  printf("%d\n",filel_no);
  for(int x=0;x<count;x++)
  {
    printf("m_fp_eachline[%d] : %ld \n",x,m_fp_eachline[x]);//Print all moving file pointer value in array
  }
  
  printf("first %d , last %d \n",first,last);
  printf("*************\n");
  
  //******************************************* Another Method **********************************************************//
  var1=m_fp_eachline[first];
  lseek(fd,var1,SEEK_SET);
  perror("lseek()");
  
  var2=m_fp_eachline[last] - m_fp_eachline[first];
  printf("var : %ld \n",var2);
  numread1=read(fd,arr,var2);
  write(1,arr,numread1);
  
  //
  
  //**************************************************************1 st Method************************************************//
  
 /* numread1 = read(fd,temp,m_fp_eachline[last]);// read upto m_fp_eachline[last] ,stored in temp
  printf("over");
  printf("*************\n");
  for(int p=m_fp_eachline[first-1];p<numread1;p++)
  {
    printf("%c",temp[p]);
  }
  printf("\n*******Game over****** \n");*/
  
  //********************************************************************2 nd Method*************************************//
 
 /*numread1 = read(fd,temp,m_fp_eachline[last]);// read upto m_fp_eachline[last] ,stored in temp
  write(1,temp,numread1);
  
  fd1=open("B.txt",O_CREAT|O_RDWR,S_IRWXU);//create a txt file
  perror("open()");
  write(fd1,temp,numread1);//stored content temp copy to fd1 of new txt file 
  
  lseek(fd1,0,SEEK_SET);//cursor move to 0th position of new file
  perror("open()");
  
  lseek(fd1,m_fp_eachline[first-1],SEEK_CUR);//In that file cursor move to m_fp_eachline[first-1],
  perror("lseek()");
  
  numread2=read(fd1,barr,SIZE); //then print
  write(1,barr,numread2);*/
 //******************************************************************************************************************************// 
  
  close(fd);
  close(fd1);
    
}




 /*


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define SIZE 3421


int main(int argc, char *argv[])
{    
  int fd,line=0;
  char arr[SIZE];
  ssize_t numread;
  off_t m_fp_eachline[SIZE],m_fp=0,coln[SIZE],count=1,count1=1;
  
  
  
  fd=open("temp.txt",O_CREAT|O_RDWR,S_IRWXU);
  perror("open()");
  
  numread=read(fd,arr,SIZE);
  perror("read()");
  write(1,arr,numread);
  
  lseek(fd,0,SEEK_SET);
  perror("lseek()");
 
  for(int i=0;i<numread;i++)
  {  
     m_fp++;
     if(arr[i]=='\n')
     { m_fp_eachline[count]=m_fp;
       count++;
       line++;
     }  
     if(arr[i]==':')
     {
       coln[count1]=m_fp;
       count1++;
     }
  }
  printf("\tline  %d \n",line);
  for(int j=0;j<count;j++)
  {
      printf("m_fp_eachline[%d] : %ld\n ",j,m_fp_eachline[j]);
  }
  for(int k=0;k<count1;k++)
  {
      printf("coln[%d] : %ld \n",k,coln[k]);
  }

    close(fd);
}




*/


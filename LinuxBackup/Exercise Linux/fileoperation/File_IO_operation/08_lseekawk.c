/* 
Name	: 
Date	: 17/12/2022
Descrition : awk command
             awk -F ":"  '{print $5}' filename.txt
             root:x:0:0:root:/root:/bin/bash 
             
             Each line has colon : 6  field 7
             
O/P	:If user want field 1 means field1 column only display




 */


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
  int fd,line=0,field;
  char arr[SIZE];
  ssize_t numread;
  off_t m_fp_eachline[SIZE],m_fp=0,coln[SIZE],count=1,count1=1;
  
  field=atoi(argv[1]);
  
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
  
  lseek(fd,0,SEEK_SET);
  perror("lseek()");
 /* 
  lseek(fd,m_fp_eachline[0],SEEK_SET);
  numread=read(fd,arr,coln[1]-m_fp_eachline[0]);
  write(1,arr,numread);
  printf("\n");	
  */
 //field1
 
 switch(field)
 {
   case 1:
     printf("************************************************field 1************************\n");
     for(int p=0,q=1;p<count,q<count1;p++,q=q+6)
     {
      lseek(fd,m_fp_eachline[p],SEEK_SET);
      numread=read(fd,arr,coln[q]-m_fp_eachline[p]);
      write(1,arr,numread);
      printf("\n");
     }
     break;
   case 2:
     printf("************************************************field 2*********************\n");
     lseek(fd,0,SEEK_SET);
     perror("lseek()");
     for(int r=1;r<count1;r=r+6)
     {
     lseek(fd,coln[r],SEEK_SET);
     numread=read(fd,arr,coln[r+1]-coln[r]);
     write(1,arr,numread);
     printf("\n");
     }
     break;
   case 3:
     printf("*********************************************field 3**********************\n");
     lseek(fd,0,SEEK_SET);
     perror("lseek()");
     for(int u=2;u<count1;u=u+6)
     {
     lseek(fd,coln[u],SEEK_SET);
     numread=read(fd,arr,coln[u+1]-coln[u]);
     write(1,arr,numread);
     printf("\n"); 
     }
     break;
  case 4:
     printf("*********************************************field 4***********************\n");
     lseek(fd,0,SEEK_SET);
     perror("lseek()");
     for(int v=3;v<count1;v=v+6)
     {
     lseek(fd,coln[v],SEEK_SET);
     numread=read(fd,arr,coln[v+1]-coln[v]);
     write(1,arr,numread);
     printf("\n"); 
     }
     break;
   case 5:
     printf("**********************************************field 5*********************\n");
     lseek(fd,0,SEEK_SET);
     perror("lseek()");
     for(int w=4;w<count1;w=w+6)
     {
     lseek(fd,coln[w],SEEK_SET);
     numread=read(fd,arr,coln[w+1]-coln[w]);
     write(1,arr,numread);
     printf("\n");
     }
     break;
   case 6:
     printf("*********************************************field 6********************\n");
     lseek(fd,0,SEEK_SET);
     perror("lseek()");
     for(int y=5;y<count1;y=y+6)
     {
     lseek(fd,coln[y],SEEK_SET);
     numread=read(fd,arr,coln[y+1]-coln[y]);
     write(1,arr,numread);
     printf("\n");   
     }
     break;
   case 7:
     printf("***********************************************field 7**********************\n");
     lseek(fd,0,SEEK_SET);
     perror("lseek()");
     for(int z=6,f=1;z<count1,f<count;z=z+6,f++)
     {
     lseek(fd,coln[z],SEEK_SET);
     numread=read(fd,arr,(m_fp_eachline[f])-(coln[z]+1));//39-29
     write(1,arr,numread);
     printf("\n");
     }
     break;
   default:
     printf("wrong selected field\n Kindly select 1 to 7\n");
  
 }
 /*
  printf("************************************************field 1************************\n");
  for(int p=0,q=1;p<count,q<count1;p++,q=q+6)
  {
    lseek(fd,m_fp_eachline[p],SEEK_SET);
    numread=read(fd,arr,coln[q]-m_fp_eachline[p]);
    write(1,arr,numread);
    printf("\n");
  }*/
  
    //field2
 /* printf("************************************************field 2*********************\n");
  lseek(fd,0,SEEK_SET);
  perror("lseek()");
  for(int r=1;r<count1;r=r+6)
  {
     lseek(fd,coln[r],SEEK_SET);
     numread=read(fd,arr,coln[r+1]-coln[r]);
     write(1,arr,numread);
     printf("\n");
     
  }*/
  
  /*lseek(fd,coln[1],SEEK_SET);
  numread=read(fd,arr,coln[2]-coln[1]);
  write(1,arr,numread);
  printf("\n");*/
  
  /*//field 3
  printf("*********************************************field 3**********************\n");
  lseek(fd,0,SEEK_SET);
  perror("lseek()");
  
  for(int u=2;u<count1;u=u+6)
  {
     lseek(fd,coln[u],SEEK_SET);
     numread=read(fd,arr,coln[u+1]-coln[u]);
     write(1,arr,numread);
     printf("\n");
     
  }*/
  
     /*lseek(fd,coln[2],SEEK_SET);
     numread=read(fd,arr,coln[3]-coln[2]);
     write(1,arr,numread);
     printf("\n");
     lseek(fd,coln[8],SEEK_SET);
     numread=read(fd,arr,coln[9]-coln[8]);
     write(1,arr,numread);
     printf("\n");*/
  
/*  //field 4
  printf("*********************************************field 4***********************\n");
  lseek(fd,0,SEEK_SET);
  perror("lseek()");
   for(int v=3;v<count1;v=v+6)
  {
     lseek(fd,coln[v],SEEK_SET);
     numread=read(fd,arr,coln[v+1]-coln[v]);
     write(1,arr,numread);
     printf("\n");
     
  }*/
  
 /* //field 5
  printf("**********************************************field 5*********************\n");
  lseek(fd,0,SEEK_SET);
  perror("lseek()");
   for(int w=4;w<count1;w=w+6)
  {
     lseek(fd,coln[w],SEEK_SET);
     numread=read(fd,arr,coln[w+1]-coln[w]);
     write(1,arr,numread);
     printf("\n");
     
  }*/
  
 /*  //field 6
   printf("*********************************************field 6********************\n");
  lseek(fd,0,SEEK_SET);
  perror("lseek()");
   for(int y=5;y<count1;y=y+6)
  {
     lseek(fd,coln[y],SEEK_SET);
     numread=read(fd,arr,coln[y+1]-coln[y]);
     write(1,arr,numread);
     printf("\n");
     
  }*/
  
 /*  //field 7
  printf("***********************************************field 7**********************\n");
  lseek(fd,0,SEEK_SET);
  perror("lseek()");
  
  for(int z=6,f=1;z<count1,f<count;z=z+6,f++)
  {
    lseek(fd,coln[z],SEEK_SET);
    numread=read(fd,arr,(m_fp_eachline[f])-(coln[z]+1));//39-29
    write(1,arr,numread);
    printf("\n");
  
  }*/
  
  /*
  lseek(fd,coln[6],SEEK_SET);
  numread=read(fd,arr,(m_fp_eachline[1])-(coln[6]+1));//39-29
  write(1,arr,numread);
  printf("\n");
  lseek(fd,coln[12],SEEK_SET);
  numread=read(fd,arr,(m_fp_eachline[2])-(coln[12]+1));//39-29
  write(1,arr,numread);
  printf("\n");*/
       
   close(fd);
}




